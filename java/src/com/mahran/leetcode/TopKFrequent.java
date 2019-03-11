package com.mahran.leetcode;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.TreeMap;
import java.util.stream.Collectors;

/*
   Author: Abdallah Mahran
   Ref: https://leetcode.com/problems/top-k-frequent-words/
   Date: 3/11/2019
*/
public class TopKFrequent{

    private class Word implements Comparable{
        private String word;
        private Integer freq;

        public Word(String w, int f) {
            word = w;
            freq = f;
        }
        /**
         * If freq of this object equals the freq of tje specified object then compare by alphabetical order,
         * otherwise compare by freq
         */
        @Override
        public int compareTo(Object o) {
            Word O = (Word) o;
            if (freq.equals(O.freq)) {
                return O.word.compareTo(word);
            }
            return freq.compareTo(O.freq);
        }
    }

    public List<String> topKFrequent(String[] words, int k) {
        PriorityQueue<Word> wordsHeap = new PriorityQueue<>();
        Map<String, Integer> wordsMapped = new HashMap<>();
        for (String w : words) {
            wordsMapped.put(w, wordsMapped.getOrDefault(w, 0) + 1);
        }

        for (Map.Entry<String, Integer> entry : wordsMapped.entrySet()) {
            wordsHeap.add(new Word(entry.getKey(), entry.getValue()));
            if (wordsHeap.size() > k) {
                wordsHeap.poll();
            }
        }
        List<String> result = new ArrayList<>();
        while (!wordsHeap.isEmpty()) {
            result.add(wordsHeap.poll().word);
        }
        Collections.reverse(result);
        return result;
    }

    // Naive solution
    public List<String> topKFrequentNaive(String[] words, int k) {
        Map<String, Integer> wordsMapped = new TreeMap<>();
        for (String word : words) {
            wordsMapped.put(word, wordsMapped.getOrDefault(word, 0) + 1);
        }

        return wordsMapped.entrySet()
                .stream()
                .sorted(Comparator.comparingInt(entry -> - 1 * entry.getValue()))
                .limit(k)
                .map(Map.Entry::getKey)
                .collect(Collectors.toList());
    }

    public static void main(String[] args) {
        System.out.println(new TopKFrequent()
                .topKFrequent(new String[]{"i", "love", "leetcode", "i", "love", "coding"}, 2)
                .toString());
        // [the, is, sunny, day]
        System.out.println(new TopKFrequent()
                .topKFrequent(new String[]{"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"}, 4)
                .toString());
    }
}
