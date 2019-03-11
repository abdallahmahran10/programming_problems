package com.mahran.geeksforgeeks;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class FindSubsets {
    public List<List<Integer>> findSubsets(List<Integer> set) {
        int subsetsSize = (1<<set.size());
        List<List<Integer>> subsets = new ArrayList<>();

        for (int i =0; i < subsetsSize; i++) {
            List<Integer> subset = new ArrayList<>();
            for (int j =0; j < set.size(); j++) {
                if (((1<<j) & i) > 0) {
                    subset.add(set.get(j));
                }
            }
            subsets.add(subset);
        }
        return subsets;
    }

    public static void main(String[] args) {
        new FindSubsets().findSubsets(List.of(1, 2, 3, 4))
                .stream()
                .sorted(Comparator.comparingInt(List::size))
                .forEach(System.out::println);
        System.out.println("---------------------------------------------------");
        new FindSubsets().findSubsets(List.of(4, 3, 2, 1))
                .stream()
                .sorted(Comparator.comparingInt(List::size))
                .forEach(System.out::println);
    }
}
