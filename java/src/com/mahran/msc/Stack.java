package com.mahran.msc;

public class Stack {
    private int[] stack;
    private int idx;

    public Stack(int s) {
        stack = new int[s];
        idx = 0;
    }

    public void push(int v) {
        if (idx == stack.length) {
            System.out.println("Stack overflow.");
            return;
        }
        stack[idx++] = v;
    }

    public int pop() {
        if (idx == 0) {
            System.out.println("Stack is empty.");
            return -1;
        }
        return stack[--idx];
    }

    public boolean isEmpty() {
        return idx ==0;
    }
}
