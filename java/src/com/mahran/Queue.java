package com.mahran;

public class Queue<T> {
    private T[] queue;
    private int tail;
    private int head;

    public Queue(int s) {
        queue = (T[]) new Object[s];
        tail = head = -1;
    }

    public void enqueue(T v) {
        if(isFull()) {
            System.out.println("Queue overflow");
            return;
        }
        if (isEmpty()) {
            tail = head = 0;
        } else {
            head = (head + 1) % queue.length;
        }
        queue[head] = v;
    }

    public T dequeue() {
        if (isEmpty()) {
            System.out.println("Queue is empty");
            return null;
        }
        T v = queue[tail];
        if (tail == head) {
            tail = head = -1;
        } else {
            tail = (tail + 1) % queue.length;
        }
        return v;
    }

    private boolean isEmpty() {
        return head == -1 && tail == -1;
    }

    private boolean isFull() {
        return (head + 1) % queue.length == tail;
    }
}
