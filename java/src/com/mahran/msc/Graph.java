package com.mahran.msc;

import com.mahran.msc.bst.TreeNode;

import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Set;
import java.util.Stack;

public class Graph {
    private final boolean directed;
    private final Map<Integer, Set<Integer>> adjacencyList;

    public Graph(boolean directed) {
        this.directed = directed;
        this.adjacencyList = new HashMap<>();
    }

    public Graph(boolean directed, TreeNode root) {
        this.directed = directed;
        this.adjacencyList = new HashMap<>();
        parseTree(root);
    }

    //
    public void printGraph() {
        adjacencyList.keySet().forEach(v -> printVertex(v, adjacencyList.get(v)) );
    }

    private void printVertex(Integer v, Set<Integer> vertexEdges) {
        System.out.println("Adjacency list of " + v + ": ");
        System.out.print(v);
        vertexEdges.forEach(a -> System.out.print("->" + a));
        System.out.println(".");
    }

    public void addEdge(int u, int v) {
        if (!adjacencyList.containsKey(u)) {
            adjacencyList.put(u, new HashSet<>());
        }
        adjacencyList.get(u).add(v);
        if (!adjacencyList.containsKey(v)) {
            adjacencyList.put(v, new HashSet<>());
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
        HashSet<Integer> visited = new HashSet<>();
        LinkedList<Integer> verticesQueue = new LinkedList<>();
        verticesQueue.add(head);
        visited.add(head);
        while (!verticesQueue.isEmpty()) {
            int vertex = verticesQueue.poll();
            System.out.print(vertex + " ");
            adjacencyList.get(vertex)
                    .stream()
                    .filter(v -> !visited.contains(v))
                    .forEach(v -> {
                        verticesQueue.add(v);
                        visited.add(v);
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
        HashSet<Integer> visited = new HashSet<>();
        Stack<Integer> verticesStack = new Stack<>();
        verticesStack.add(head);
        visited.add(head);
        while (!verticesStack.isEmpty()) {
            int vertex = verticesStack.pop();
            System.out.print(vertex + " ");
            adjacencyList.get(vertex)
                    .stream()
                    .filter(v -> !visited.contains(v))
                    .forEach(v -> {
                        verticesStack.add(v);
                        visited.add(v);
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

        HashSet<Integer> visited = new HashSet<>();
        Stack<Integer> verticesStack = new Stack<>();
        adjacencyList.keySet()
                .stream()
                .filter(v -> !visited.contains(v))
                .forEach( v -> topologicalSort(v, visited, verticesStack));
        while (!verticesStack.isEmpty()) {
            System.out.print(verticesStack.pop() + " ");
        }
        System.out.println();
    }

    private void topologicalSort(Integer vertex, HashSet<Integer> visited, Stack<Integer> verticesStack) {
        visited.add(vertex);
        adjacencyList.get(vertex)
                .stream()
                .filter(v -> !visited.contains(v))
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
        HashSet<Integer> visited = new HashSet<>();
        Stack<Integer> verticesStack = new Stack<>();
        verticesStack.add(src);
        visited.add(src);
        while (!verticesStack.isEmpty()) {
            int vertex = verticesStack.pop();
            for (int v : adjacencyList.get(vertex)) {
                if (!visited.contains(v)) {
                    if (v == dst) {
                        return true;
                    }
                    verticesStack.add(v);
                    visited.add(v);
                }
            }
        }
        return false;
    }

    public int shortestDistance(int src, int dst) {
        Map<Integer, Integer> distances = new HashMap<>();
        Map<Integer, Integer> prevNodeInPath = new HashMap<>();
        if (!isPathExists(src, dst, distances, prevNodeInPath)) {
            System.out.println("No path from " + src + " to " + dst);
            return -1;
        }

        Stack<Integer> pathStack = new Stack<>();
        int crawl = dst;
        pathStack.push(crawl);
        while(crawl != src) {
            crawl = prevNodeInPath.get(crawl);
            pathStack.push(crawl);
        }
        System.out.print("Path: ");
        while (!pathStack.isEmpty()) {
            System.out.print(pathStack.pop() + (pathStack.size() == 0? "" : "->"));
        }
        System.out.println("\nDistance: " + distances.get(dst));
        return distances.get(dst);
    }


    private boolean isPathExists(int src, int dst,  Map<Integer, Integer> distances, Map<Integer, Integer> prevNodeInPath) {
        if (!adjacencyList.containsKey(src) || !adjacencyList.containsKey(dst)) {
            return false;
        }

        if (src == dst) {
            return true;
        }
        HashSet<Integer> visited = new HashSet<>();
        Stack<Integer> verticesStack = new Stack<>();
        verticesStack.add(src);
        visited.add(src);
        distances.put(src, 0);
        while (!verticesStack.isEmpty()) {
            int vertex = verticesStack.pop();
            for (int adjVertex : adjacencyList.get(vertex)) {
                if (!visited.contains(adjVertex)) {
                    distances.put(adjVertex, distances.get(vertex) + 1);
                    prevNodeInPath.put(adjVertex, vertex);
                    if (adjVertex == dst) {
                        return true;
                    }
                    verticesStack.add(adjVertex);
                    visited.add(adjVertex);
                }
            }
        }
        return false;
    }
    //
    private void parseTree(TreeNode root) {
        Queue<TreeNode> vertices = new LinkedList<>();
        vertices.add(root);
        while (!vertices.isEmpty()) {
            TreeNode node = vertices.poll();
            if (!adjacencyList.containsKey(node.getValue())) {
                adjacencyList.put(node.getValue(), new HashSet<>());
            }
            if (node.hasLeftNode()) {
                vertices.add(node.getLeft());
                adjacencyList.get(node.getValue()).add(node.getLeft().getValue());
            }
            if (node.hasRightNode()) {
                vertices.add(node.getRight());
                adjacencyList.get(node.getValue()).add(node.getRight().getValue());
            }
        }
    }
}
