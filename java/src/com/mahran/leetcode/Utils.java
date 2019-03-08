package com.mahran.leetcode;

public class Utils {
    private static TreeNode buildBSTFromSortedArray(int[] arr, int s, int e) {
        if (s > e) {
            return null;
        }
        if (s == e) {
            return new TreeNode(arr[s]);
        }
        int mid = (e-s) / 2 + s;
        TreeNode node = new TreeNode(arr[s]);
        node.val = arr[mid];
        node.left = buildBSTFromSortedArray(arr, s, mid -1);
        node.right = buildBSTFromSortedArray(arr, mid + 1, e);
        return node;
    }

    public static TreeNode buildBSTFromSortedArray(int[] arr) {
        return buildBSTFromSortedArray(arr, 0, arr.length-1);
    }
}
