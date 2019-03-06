package com.mahran;

import java.util.HashMap;
import java.util.Map;

public class Trie {
    TrieLeaf head = new TrieLeaf();

    private class TrieLeaf {
        private Map<Character, TrieLeaf> characterMap;
        private boolean isEndOfWord;

        TrieLeaf() {
            this.characterMap = new HashMap<>();
        }
    }

    public void add(String word) {
        TrieLeaf slider = head;
        for (char c : word.toCharArray()) {
            slider = slider.characterMap
                    .computeIfAbsent(c, character -> new TrieLeaf());
        }
        slider.isEndOfWord = true;
    }

    public boolean search(String word) {
        TrieLeaf slider = head;
        if (slider == null) {
            return false;
        }
        for (char c : word.toCharArray()) {
            if (slider.characterMap.containsKey(c)) {
                slider = slider.characterMap.get(c);
            } else {
                return false;
            }
        }
        return slider.isEndOfWord;
    }
}
