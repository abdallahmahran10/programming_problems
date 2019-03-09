package com.mahran.leetcode;

import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Set;
import java.util.Stack;
import java.util.stream.Collectors;

/*
   Author: Abdallah Mahran
   Ref: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
   Date: 3/8/2019
*/
public class DistanceK {
    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        if (root == null || target == null) {
            return Collections.emptyList();
        }
        Map<Integer, Set<Integer>> adjacencyList = toGraph(root);
        printGraph(adjacencyList);
        Map<Integer, Integer> distances = new HashMap<>();
        findDistancesFromTarget(adjacencyList, target.val, distances);
        return distances.entrySet()
                .stream()
                .filter(entry -> entry.getValue() == K)
                .map(Map.Entry::getKey)
                .collect(Collectors.toList());
    }

    private void findDistancesFromTarget(Map<Integer, Set<Integer>> adjacencyList, int target, Map<Integer, Integer> distances) {
        Map<Integer, Boolean> visited = new HashMap<>();
        adjacencyList.keySet().forEach(k -> visited.put(k, false));
        distances.put(target, 0);
        Stack<Integer> verticesStack = new Stack<>();
        verticesStack.push(target);
        visited.put(target, true);
        while (!verticesStack.isEmpty()) {
            Integer v = verticesStack.pop();
            for (int adjVertex : adjacencyList.get(v)) {
                if (!visited.get(adjVertex)) {
                    verticesStack.push(adjVertex);
                    distances.put(adjVertex, distances.get(v) + 1);
                    visited.put(adjVertex, true);
                }

            }
        }
    }

    private Map<Integer, Set<Integer>> toGraph(TreeNode root) {
        Map<Integer, Set<Integer>> adjacencyList = new HashMap<>();
        Queue<TreeNode> vertices = new LinkedList<>();
        vertices.add(root);
        while (!vertices.isEmpty()) {
            TreeNode node = vertices.poll();
            if (!adjacencyList.containsKey(node.val)) {
                adjacencyList.put(node.val, new HashSet<>());
            }
            if (node.left != null) {
                vertices.add(node.left);
                adjacencyList.get(node.val).add(node.left.val);

                if (!adjacencyList.containsKey(node.left.val)) {
                    adjacencyList.put(node.left.val, new HashSet<>());
                }
                adjacencyList.get(node.left.val).add(node.val);
            }
            if (node.right != null) {
                vertices.add(node.right);
                adjacencyList.get(node.val).add(node.right.val);

                if (!adjacencyList.containsKey(node.right.val)) {
                    adjacencyList.put(node.right.val, new HashSet<>());
                }
                adjacencyList.get(node.right.val).add(node.val);
            }
        }
        return adjacencyList;
    }


    public void printGraph(Map<Integer, Set<Integer>> adjacencyList) {
        adjacencyList.keySet().forEach(v -> printVertex(v, adjacencyList.get(v)) );
    }

    private void printVertex(Integer v, Set<Integer> vertexEdges) {
        System.out.println("Adjacency list of " + v + ": ");
        System.out.print(v);
        vertexEdges.forEach(a -> System.out.print("->" + a));
        System.out.println(".");
    }
}
