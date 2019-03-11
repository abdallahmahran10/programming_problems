package com.mahran;

import com.mahran.leetcode.TreeNode;
import com.mahran.leetcode.Utils;
import com.mahran.msc.bst.BinarySearchTree;
public class Main {

	public static void main(String[] args) {
		TreeNode root = new TreeNode(20);
		root.left = new TreeNode(8);
		root.left.left = new TreeNode(4);
		root.left.right = new TreeNode(12);
		root.left.right.left = new TreeNode(10);
		root.left.right.right = new TreeNode(14);
//		root.right = new TreeNode(22);
//		root.right.right = new TreeNode(25);
		BinarySearchTree bst = new BinarySearchTree(Utils.toMyTreeNode(root));
		bst.printBoundary();
	}
}
