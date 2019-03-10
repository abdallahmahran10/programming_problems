package com.mahran.leetcode;

import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.stream.Collectors;

/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/
	Date: 3/9/2019
*/
public class KSmallestPairs {
    private class Pair implements Comparable<Pair>{
        final int x, y;
        final long sum;
        Pair(int i, int j) {
            x = i;
            y = j;
            sum = x + y;
        }

        @Override
        public String toString() {
            return "(" + x + "," + y + ")";
        }

        /**
         * Compares this object with the specified object for order.  Returns a
         * negative integer, zero, or a positive integer as this object is greater
         * than, equal to, or less than the specified object.
         */
        @Override
        public int compareTo(Pair o) {
            if (o == null) {
                throw new NullPointerException();
            }
            long sumO = o.x + o.y;
            if (sum < sumO) {
                return -1;
            }
            if (sum > sumO) {
                return 1;
            }
            return 0;
        }
    }

    public List<int[]> kSmallestPairs1(int[] nums1, int[] nums2, int k) {
        PriorityQueue<Pair> pairs = new PriorityQueue<>();
        for (int i=0; i < nums1.length; i++) {
            for (int j=0; j < nums2.length; j++) {
                pairs.add(new Pair(nums1[i] ,nums2[j]));
            }
        }

        return pairs.stream()
                .limit(k)
                .map(pair -> new int[]{pair.x, pair.y})
                .collect(Collectors.toList());
    }

    public List<int[]> kSmallestPairs0(int[] nums1, int[] nums2, int k) {

        int[] a1 = new int[]{1, 1, 2};
        int[] a2 = new int[]{1, 2, 3};

        PriorityQueue<Pair> pairsMaxHeap = new PriorityQueue<>();
        int i=0, j=0;
        while (i < nums1.length && j < nums2.length) {
            if (pairsMaxHeap.size() == k) {
                break;
            }

            Pair pair = new Pair(nums1[i], nums2[j]);
            pairsMaxHeap.add(pair);
            if (j == nums2.length - 1) {
                i++;
            } else if (i == nums1.length - 1) {
                j ++;
            } else {
                if ((nums1[i + 1] + nums2[j]) <= (nums1[i] + nums2[j + 1])) {
                    i++;
                } else {
                    j++;
                }
            }
        }
        return pairsMaxHeap.stream()
                .map(pair -> new int[]{pair.x, pair.y})
                .collect(Collectors.toList());
    }

    public List<int[]> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        PriorityQueue<int[]> que = new PriorityQueue<>((a,b)->a[0]+a[1]-b[0]-b[1]);
        List<int[]> res = new ArrayList<>();
        if (nums1.length==0 || nums2.length==0 || k==0) {
            return res;
        }
        for (int i=0; i<nums1.length && i<k; i++) {
            que.offer(new int[]{nums1[i], nums2[0], 0});
        }
        while (k-- > 0 && !que.isEmpty()){
            int[] cur = que.poll();
            res.add(new int[]{cur[0], cur[1]});
            int idxOfElementInNum2 = cur[2];
            if (idxOfElementInNum2 == nums2.length-1) {
                continue;
            }
            que.offer(new int[]{cur[0],nums2[idxOfElementInNum2 + 1], cur[2]+1});
        }
        return res;
    }
}
