package com.mahran.bst;

import lombok.Builder;
import lombok.Getter;

import java.util.Arrays;

@Builder
public class BinarySearchTree {
    @Getter
    TreeNode root;

    public static BinarySearchTree createBST(int[] arr) {
        Arrays.sort(arr);
        return buildBSTFromSortedArray(arr);
    }

    public static BinarySearchTree buildBSTFromSortedArray(int[] arr) {
        return BinarySearchTree.builder()
                .root(buildBSTFromSortedArray(arr, 0, arr.length-1))
                .build();
    }

    private static TreeNode buildBSTFromSortedArray(int[] arr, int s, int e) {
        if (s > e) {
            return null;
        }
        if (s == e) {
            return TreeNode.builder()
                    .value(arr[s])
                    .build();
        }
        int mid = (e-s) / 2 + s;
        return TreeNode.builder()
                .value(arr[mid])
                .left(buildBSTFromSortedArray(arr, s, mid -1))
                .right(buildBSTFromSortedArray(arr, mid + 1, e))
                .build();
    }

    public void insertNode(TreeNode node) {

    }

    public boolean search(int v) {
        return search(root, v);
    }

    private boolean search(TreeNode node, int v) {
        if (node == null) {
            return false;
        }

        if (node.getValue() == v) {
            return true;
        }
        if (node.getValue() > v) {
            return search(node.getLeft(), v);
        } else {
            return search(node.getRight(), v);
        }
    }

    public void preOrderPrint() {
        System.out.println("\nPreorder traversal: ");
        preOrderPrint(root);
    }

    private void preOrderPrint(TreeNode node) {
        if (node == null) {
            return;
        }
        System.out.print(node.getValue() + " ");
        inOrderPrint(node.getLeft());
        inOrderPrint(node.getRight());
    }

    public void inOrderPrint() {
        System.out.println("\nInorder traversal: ");
        inOrderPrint(root);
    }

    private void inOrderPrint(TreeNode node) {
        if (node == null) {
            return;
        }
        inOrderPrint(node.getLeft());
        System.out.print(node.getValue() + " ");
        inOrderPrint(node.getRight());
    }
    public void postOrderPrint() {
        System.out.println("\nPostorder traversal: ");
        postOrderPrint(root);
    }

    private void postOrderPrint(TreeNode node) {
        if (node == null) {
            return;
        }
        inOrderPrint(node.getLeft());
        inOrderPrint(node.getRight());
        System.out.print(node.getValue() + " ");
    }
}
