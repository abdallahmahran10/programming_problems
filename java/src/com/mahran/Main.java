package com.mahran;

import com.mahran.leetcode.DistanceK;
import com.mahran.leetcode.TreeNode;

public class Main {

	public static void main(String[] args) {
		TreeNode root = new TreeNode(3);
		root.right = new TreeNode(1);
		root.right.left = new TreeNode(0);
		root.right.right = new TreeNode(8);

		root.left = new TreeNode(5);
		root.left.left = new TreeNode(6);
		root.left.right = new TreeNode(2);
		root.left.right.left = new TreeNode(7);
		root.left.right.right = new TreeNode(4);
		DistanceK distanceK = new DistanceK();
        distanceK.distanceK(root, new TreeNode(5), 2).forEach(System.out::println);
//		TreeNode root = TreeNode.builder()
//				.value(1)
//				.left(TreeNode.builder()
//						.value(2)
//						.left(TreeNode.builder()
//								.value(4)
//								.build())
//						.build())
//				.right(TreeNode.builder()
//						.value(3)
//						.build())
//				.build();
//		Graph graph = new Graph(true);
//		graph.addEdge(5, 2);
//		graph.addEdge(5, 0);
//		graph.addEdge(4, 0);
//		graph.addEdge(4, 1);
//		graph.addEdge(2, 3);
//		graph.addEdge(3, 1);
//
//		graph.printGraph();
//		graph.breadthFirstTraversal(5);
//		graph.depthFirstTraversal(5);
//		graph.topologicalSort();
//		System.out.println(graph.isPathExists(5, 1));
//		graph.shortestDistance(5, 1);
	}

}
