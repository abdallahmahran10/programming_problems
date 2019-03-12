package com.mahran.leetcode;

import java.util.Arrays;

/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/target-sum/
	Date: 3/6/2019
*/
public class FindTargetSumWays {

    public int findTargetSumWays(int[] nums, int S) {
        int[][] memory = new int[nums.length][2001];
        for (int[] row : memory)
            Arrays.fill(row, Integer.MIN_VALUE);
        return calculate(nums, 0, 0, S, memory);
    }

    private int calculate(int[] nums, int i, int sum, int targetSum, int[][] memory) {
        if (i == nums.length) {
            if (sum == targetSum) {
                return 1;
            } else {
                return 0;
            }
        } else {
            if (memory[i][sum + 1000] != Integer.MIN_VALUE) {
                return memory[i][sum + 1000];
            }
            int neg = calculate(nums, i + 1, sum + nums[i], targetSum, memory);
            int pos = calculate(nums, i + 1, sum - nums[i], targetSum, memory);
            memory[i][sum + 1000] = neg + pos;
            return memory[i][sum + 1000];
        }
    }


    public static void main(String[] args) {
        System.out.println(new FindTargetSumWays().findTargetSumWays(new int[]{19,32,36,7,37,10,44,21,40,39,39,18,5,34,3,40,33,2,46,46}, 29));
        System.out.println(new FindTargetSumWays().findTargetSumWays(new int[]{1,1,1,1,1}, 3));
        System.out.println(new FindTargetSumWays().findTargetSumWays(new int[]{1,1}, 2));
        System.out.println(new FindTargetSumWays().findTargetSumWays(new int[]{1,2}, 1));
        System.out.println(new FindTargetSumWays().findTargetSumWays(new int[]{1,2,7,9,981}, 1000000000));
    }
}
