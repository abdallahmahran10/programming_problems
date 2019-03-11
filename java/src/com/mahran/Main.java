package com.mahran;

import com.mahran.msc.Graph;

public class Main {

	public static void main(String[] args) {
		Graph g = new Graph(true);
		g.addEdge(1, 2);
		g.addEdge(2, 4);
		g.addEdge(2, 20);
		g.addEdge(20, 4);
		g.addEdge(4, 5);
		g.addEdge(4, 6);
		g.addEdge(6, 7);
		g.addEdge(7, 5);
		g.addEdge(1, 3);
		g.addEdge(3, 5);
		g.printGraph();
		g.shortestDistance(1, 5);
		g.pathFinder(1, 5).forEach(System.out::println);
	}
}
