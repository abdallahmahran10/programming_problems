package com.mahran;

import com.mahran.msc.Graph;

import java.util.Arrays;

public class Main {

	public static void main(String[] args) {
		Graph g = new Graph(true);

		g.addEdge(0, 1);
		g.addEdge(0, 2);
		g.addEdge(1, 2);
		g.addEdge(2, 0);
		g.addEdge(2, 3);
		g.addEdge(3, 3);

		g.printGraph();
		short[][] transitiveClosureMatrix = g.transitiveClosure();
		for (short[] vTransitiveClosure : transitiveClosureMatrix) {
			System.out.println(Arrays.toString(vTransitiveClosure));
		}
	}
}
