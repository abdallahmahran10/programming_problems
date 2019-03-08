package com.mahran;

import com.mahran.msc.Graph;

public class Main {

	public static void main(String[] args) {
		Graph graph = new Graph(true);

		graph.addEdge(5, 2);
		graph.addEdge(5, 0);
		graph.addEdge(4, 0);
		graph.addEdge(4, 1);
		graph.addEdge(2, 3);
		graph.addEdge(3, 1);

		graph.printGraph();
		graph.breadthFirstTraversal(5);
		graph.depthFirstTraversal(5);
		graph.topologicalSort();
		System.out.println(graph.isPathExists(5, 4));
	}
}
