package com.mahran;

import com.mahran.msc.Graph;

public class Main {

	public static void main(String[] args) {
		Graph g = new Graph(true);
		g.addEdge(0, 1);
		g.addEdge(0, 2);
		g.addEdge(1, 3);
		g.addEdge(4, 1);
		g.addEdge(6, 4);
		g.addEdge(5, 6);
		g.addEdge(5, 2);
		g.addEdge(6, 0);

		g.printGraph();
		System.out.println(g.findMother());
	}
}
