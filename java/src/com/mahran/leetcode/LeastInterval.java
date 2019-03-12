package com.mahran.leetcode;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;
/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/task-scheduler/
	Date: 3/6/2019
*/
public class LeastInterval {
    public int leastInterval(char[] tasks, int n) {
        int intervals = 0;
        int[] tasksCount = new int[26];
        for (char c: tasks)
            tasksCount[c - 'A']++;
        PriorityQueue<Integer> tasksQueue = new PriorityQueue<>(26, Comparator.reverseOrder());
        for (int count: tasksCount) {
            if (count > 0)
                tasksQueue.add(count);
        }
        while(!tasksQueue.isEmpty()) {
            int i = 0;
            List<Integer> reAdd = new ArrayList<>();
            while (i <= n) {
                if (!tasksQueue.isEmpty()) {
                    Integer remaining = tasksQueue.poll();
                    if (--remaining > 0) {
                        reAdd.add(remaining);
                    }
                }
                intervals++;
                if (reAdd.size() == 0 && tasksQueue.isEmpty()) {
                    break;
                }
                i++;
            }
            tasksQueue.addAll(reAdd);
        }
        return intervals;
    }
    public static void main(String[] args) {
        System.out.println(new LeastInterval().leastInterval(new char[]{'A','A','B','B','B'}, 2));
        System.out.println(new LeastInterval().leastInterval(new char[]{'A','A','A','B','B','B'}, 2));
        System.out.println(new LeastInterval().leastInterval(new char[]{'A','A','A','A','A','A','B','C','D','E','F','G'}, 2));
    }
}
