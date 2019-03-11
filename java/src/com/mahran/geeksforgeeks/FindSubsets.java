package com.mahran.geeksforgeeks;

import java.util.ArrayList;
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
}
