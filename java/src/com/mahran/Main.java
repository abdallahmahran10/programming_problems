package com.mahran;

import com.mahran.leetcode.FindTilt;
import com.mahran.leetcode.TreeNode;
import com.mahran.leetcode.Utils;

public class Main {

	public static void main(String[] args) {
		TreeNode bst = Utils.buildBSTFromSortedArray(new int[]{1, 2, 3, 4});

		TreeNode node = new TreeNode(1);
		node.left = new TreeNode(2);
		node.right = new TreeNode(3);
		node.left.left = new TreeNode(4);
//		node.right.left = new TreeNode(5);
//		node.right = new TreeNode(3);
//		node.right.left = new TreeNode(6);
//		node.right.right = new TreeNode(7);

		System.out.println(new FindTilt().findTilt(node));
	}

}
