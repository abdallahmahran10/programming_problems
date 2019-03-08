package com.mahran.msc;

public class TStack<T> {
    private T[] stack;
    private int idx;

    public TStack(int s) {
        stack = (T[]) new Object[s];
        idx = 0;
    }

    public void push(T v) {
        if (idx == stack.length) {
            System.out.println("TStack overflow.");
            return;
        }
        stack[idx++] = v;
    }

    public T pop() {
        if (idx == 0) {
            System.out.println("TStack is empty.");
            return null;
        }
        return stack[--idx];
    }

    public boolean isEmpty() {
        return idx ==0;
    }
}
