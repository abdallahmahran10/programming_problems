package com.mahran.leetcode;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/binary-tree-paths/
	Date: 3/6/2019
*/
public class BinaryTreePaths {

    public List<String> binaryTreePaths(TreeNode root) {
        List<String> paths = new ArrayList<>();
        if (root == null) {
            return Collections.emptyList();
        }
        binaryTreePath(root, paths, "");
        return paths;
    }

    private void binaryTreePath(TreeNode node, List<String> paths, String currentPath) {
        currentPath += node.val;
        if (isLeaf(node)) {
            paths.add(currentPath);
        }
        currentPath += "->";
        if (node.right != null) {
            binaryTreePath(node.right, paths, currentPath);
        }

        if (node.left != null) {
            binaryTreePath(node.left, paths, currentPath);
        }
    }

    private boolean isLeaf(TreeNode node) {
        return node.left == null && node.right == null;
    }
}
