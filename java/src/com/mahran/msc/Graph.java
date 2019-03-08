package com.mahran.msc;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Stack;

public class Graph {
    private final boolean directed;
    private final Map<Integer, List<Integer>> adjacencyList;

    public Graph(boolean directed) {
        this.directed = directed;
        this.adjacencyList = new HashMap<>();
    }

    //
    public void printGraph() {
        adjacencyList.keySet().forEach(v -> printVertex(v, adjacencyList.get(v)) );
    }

    private void printVertex(Integer v, List<Integer> vertexEdges) {
        System.out.println("Adjacency list of " + v + ": ");
        System.out.print(v);
        vertexEdges.forEach(a -> System.out.print("->" + a));
        System.out.println(".");
    }

    public void addEdge(int u, int v) {
        if (!adjacencyList.containsKey(u)) {
            adjacencyList.put(u, new ArrayList<>());
        }
        adjacencyList.get(u).add(v);
        if (!adjacencyList.containsKey(v)) {
            adjacencyList.put(v, new ArrayList<>());
        }
        if (!directed) {
            adjacencyList.get(v).add(u);
        }

    }
    //
    public void breadthFirstTraversal(int head) {
        if (!adjacencyList.containsKey(head)) {
            System.out.println("Vertex does not exists");
            return;
        }
        System.out.println("Breadth First Traversal: ");
        HashMap<Integer, Boolean> visited = new HashMap<>();
        adjacencyList.keySet().forEach(v -> visited.put(v, false));
        LinkedList<Integer> verticesQueue = new LinkedList<>();
        verticesQueue.add(head);
        visited.put(head, true);
        while (!verticesQueue.isEmpty()) {
            int vertex = verticesQueue.poll();
            System.out.print(vertex + " ");
            adjacencyList.get(vertex)
                    .stream()
                    .filter(v -> !visited.get(v))
                    .forEach(v -> {
                        verticesQueue.add(v);
                        visited.put(v, true);
                    });
        }
        System.out.println();
    }
    //
    public void depthFirstTraversal(int head) {
        if (!adjacencyList.containsKey(head)) {
            System.out.println("Vertex does not exists");
            return;
        }
        System.out.println("Depth First Traversal: ");
        HashMap<Integer, Boolean> visited = new HashMap<>();
        adjacencyList.keySet().forEach(v -> visited.put(v, false));
        Stack<Integer> verticesQueue = new Stack<>();
        verticesQueue.add(head);
        visited.put(head, true);
        while (!verticesQueue.isEmpty()) {
            int vertex = verticesQueue.pop();
            System.out.print(vertex + " ");
            adjacencyList.get(vertex)
                    .stream()
                    .filter(v -> !visited.get(v))
                    .forEach(v -> {
                        verticesQueue.add(v);
                        visited.put(v, true);
                    });
        }
        System.out.println();
    }

    /**
     * Tension is building inside steadily
     * (Everyone feels so far away from me)
     * Happy thoughts forcing their way out of me
     * (Trying not to break but I'm so tired of this deceit)
     * (Every time I try to make myself get back up on my feet)
     * (All I ever think about is this)
     * (All the tiring time between)
     * (And how trying to put my trust in you just takes so much out of me)
     */
    public void topologicalSort() {
        if (adjacencyList.isEmpty()) {
            System.out.println("Graph is empty");
            return;
        }
        System.out.println("Topological: ");

        HashMap<Integer, Boolean> visited = new HashMap<>();
        adjacencyList.keySet().forEach(v -> visited.put(v, false));
        Stack<Integer> verticesStack = new Stack<>();
        adjacencyList.keySet()
                .stream()
                .filter(v -> !visited.get(v))
                .forEach( v -> topologicalSort(v, visited, verticesStack));
        while (!verticesStack.isEmpty()) {
            System.out.print(verticesStack.pop() + " ");
        }
        System.out.println();
    }

    private void topologicalSort(Integer vertex, HashMap<Integer, Boolean> visited, Stack<Integer> verticesStack) {
        visited.put(vertex, true);
        adjacencyList.get(vertex)
                .stream()
                .filter(v -> !visited.get(v))
                .forEach(v -> topologicalSort(v, visited, verticesStack));
        verticesStack.push(vertex);
    }
    //
    public boolean isPathExists(int src, int dst) {
        if (!adjacencyList.containsKey(src) || !adjacencyList.containsKey(dst)) {
            return false;
        }

        if (src == dst) {
            return true;
        }
        HashMap<Integer, Boolean> visited = new HashMap<>();
        adjacencyList.keySet().forEach(v -> visited.put(v, false));
        Stack<Integer> verticesQueue = new Stack<>();
        verticesQueue.add(src);
        visited.put(src, true);
        while (!verticesQueue.isEmpty()) {
            int vertex = verticesQueue.pop();
            for (int v : adjacencyList.get(vertex)) {
                if (!visited.get(v)) {
                    if (v == dst) {
                        return true;
                    }
                    verticesQueue.add(v);
                    visited.put(v, true);
                }
            }
        }
        return false;
    }

}
