package com.mahran;

import com.mahran.msc.bst.BinarySearchTree;

public class Main {

	public static void main(String[] args) {
		BinarySearchTree bst = BinarySearchTree.createBST(new int[]{1,2,3,4});
		bst.insertNode(6);
		bst.insertNode(7);
		System.out.println(bst.minDepth());
		System.out.println(bst.height());
	}

}
