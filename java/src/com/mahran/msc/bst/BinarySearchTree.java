package com.mahran.msc.bst;

import lombok.Builder;
import lombok.Getter;

import java.util.*;

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
    //
    public void insertNode(int v) {
        if (root == null) {
            root = TreeNode.builder().value(v).build();
        } else {
            insertNode(root, v);
        }
    }

    private void insertNode(TreeNode node, int v) {
        if (node.getValue() == v) {
            return;
        } else if (node.getValue() > v) {
            if (node.getLeft() == null) {
                node.setLeft(TreeNode.builder().value(v).build());
            } else {
                insertNode(node.getLeft(), v);
            }
        } else {
            if (node.getRight() == null) {
                node.setRight(TreeNode.builder().value(v).build());
            } else {
                insertNode(node.getRight(), v);
            }
        }
    }
    //
    public boolean search(int v) {
        return search(root, v);
    }

    private boolean search(TreeNode node, int v) {
        return findNode(node, v) != null;
    }

    public TreeNode findNode(TreeNode node, int v) {
        if (node == null) {
            return null;
        }

        if (node.getValue() == v) {
            return node;
        }
        if (node.getValue() > v) {
            return findNode(node.getLeft(), v);
        } else {
            return findNode(node.getRight(), v);
        }
    }
    //
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
    //
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
    //
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
    //
    public void deleteNode(int v) {
        root = deleteNode(root, v);
    }

    private TreeNode deleteNode(TreeNode node, int v) {
        if (node == null) {
            return null;
        } else if(node.getValue() == v) { // found the node
            return rotate(node);
        } else if (node.getValue() > v) {
            node.setLeft(deleteNode(node.getLeft(), v));
        } else {
            node.setRight(deleteNode(node.getRight(), v));
        }
        return node;
    }

    private TreeNode rotate(TreeNode node) {
        if (node.isLeaf()) {
            return null;
        }
        // full house
        if (node.hasTwoChildren()) {
            TreeNode min = findMin(node.getRight());
            node.setValue(min.getValue());
            node.setRight(deleteNode(node.getRight(), min.getValue()));
            return node;
        }
        // has one branch
        if (node.hasLeftNode()) {
            return node.getLeft();
        } else {
            return node.getRight();
        }
    }

    private TreeNode findMin(TreeNode node) {
        TreeNode slider = node;
        while(slider.getLeft() != null) {
            slider = slider.getLeft();
        }
        return slider;
    }
    //
    public int minDepth() {
        return minDepth(root);
    }

    private int minDepth(TreeNode node) {
        if (node == null) {
            return 0;
        }
        if(node.isLeaf()) {
            return 1;
        }

        if(node.hasTwoChildren()) {
            return Math.min(minDepth(node.getRight()), minDepth(node.getLeft())) + 1;
        }

        if (node.hasRightNode()) {
            return minDepth(node.getRight()) + 1;
        } else {
            return minDepth(node.getLeft()) + 1;
        }
    }
    //
    public int maxDepth() {
        return maxDepth(root);
    }

    private int maxDepth(TreeNode node) {
        if (node == null) {
            return 0;
        }
        if(node.isLeaf()) {
            return 1;
        }

        if(node.hasTwoChildren()) {
            return Math.max(maxDepth(node.getRight()), maxDepth(node.getLeft())) + 1;
        }

        if (node.hasRightNode()) {
            return maxDepth(node.getRight()) + 1;
        } else {
            return maxDepth(node.getLeft()) + 1;
        }
    }
    //
    public int height() {
        return height(root);
    }

    private int height(TreeNode node) {
        if (node == null) {
            return -1;
        }
        return Math.max(height(node.getRight()), height(node.getLeft())) + 1;
    }
    // Breadth first traversal
    public void printLevelOrder() {
        Queue<TreeNode> nodesQueue = new LinkedList<>();
        if (root == null) {
            return;
        }
        TreeNode slider = root;
        while(slider != null) {
            System.out.print(slider.getValue() + " ");
            if (slider.hasLeftNode()) {
                nodesQueue.add(slider.getLeft());
            }
            if (slider.hasRightNode()) {
                nodesQueue.add(slider.getRight());
            }
            slider = nodesQueue.poll();
        }
    }

}
