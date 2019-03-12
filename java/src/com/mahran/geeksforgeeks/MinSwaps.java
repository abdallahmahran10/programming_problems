package com.mahran.geeksforgeeks;

import java.util.AbstractMap.SimpleEntry;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/*
   Author: Abdallah Mahran
   Ref: https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/
   Date: 3/11/2019
*/
public class MinSwaps {

    public int minSwaps(int[] a) {
        if (a.length < 2) {
            return 0;
        }
        SimpleEntry<Integer, Integer>[] pairs = new SimpleEntry[a.length];
        for (int i =0; i < a.length; i++) {
            pairs[i] = new SimpleEntry(a[i], i);
        }
        Arrays.sort(pairs, Comparator.comparingInt(SimpleEntry::getKey));
        Set<Integer> visited = new HashSet<>();
        int swaps = 0;
        for (int i = 0; i < pairs.length; i++) {
            SimpleEntry<Integer, Integer> pair = pairs[i];
            if (visited.contains(pair.getKey()) || pair.getValue() == i) {
                continue;
            }
            int j = i;
            int swapsForCurrentElement = 0;
            while (!visited.contains(j)) {
                visited.add(j);
                j = pairs[j].getValue();
                swapsForCurrentElement++;
            }
            swaps += Math.max(--swapsForCurrentElement, 0);


        }
        return swaps;
    }

    public static void main(String[] args) {
        System.out.println(new MinSwaps().minSwaps(new int[]{1,3,2,6,4,5}));
    }
}
