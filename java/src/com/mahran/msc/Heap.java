package com.mahran.msc;

public class Heap {
    int[] heap;
    int size;

    public Heap(int size) {
        heap = new int[size];
        size = 0;
    }

    private void minHeapify(int i) {
        int l = left(i);
        int r = right(i);
        int newIdx = i;
        if (l < heap.length && heap[l] < heap[i]) {
            newIdx = l;
        }
        if (r < heap.length && heap[r] < heap[newIdx]){
            newIdx = r;
        }
        if (newIdx != i) {
            swap(newIdx, i);
            minHeapify(newIdx);
        }

    }
    // index of parent child of node at index i
    int parent(int i) {
        return (i - 1) / 2;
    }
    // index of left child of node at index i
    int left(int i) {
        return  (2 * i) + 1;
    }
    // index of right child of node at index i
    int right(int i) {
        return (2 * i) + 2;
    }

    // to extract the root which is the minimum element
    int extractMin() {
        if (size == 1) {
            return heap[size--];
        }
        if (size == 0) {
            return Integer.MAX_VALUE;
        }
        int min = heap[0];
        heap[0] = heap[--size];
        minHeapify(0);
        return min;
    }

    // Decreases key value of key at index i to new_val
    void decreaseKey(int i, int val){
        if (heap[i] <= val) {
            return;
        }
        heap[i] = val;
        while (i !=0 && heap[parent(i)] > heap[i]) {
            swap(parent(i), i);
            i = parent(i);
        }
    }

    // Returns the minimum key (key at root) from min heap
    int getMin() {
        return heap[0];
    }

    // Deletes a key stored at index i
    void deleteKey(int i) {
        if (i >= size) {
            return;
        }
        heap[i] = Integer.MAX_VALUE;
        size--;
        minHeapify(i);
    }

    // Inserts a new key 'k'
    void insertKey(int k) {
        if (size == heap.length) {
            System.out.println("Heap overflow");
        }
        int i = size++;
        heap[i] = k;
        while (i !=0 && heap[parent(i)] > heap[i]) {
            swap(parent(i), i);
            i = parent(i);
        }
    }

    public boolean isEmpty() {
        return size == 0;
    }

    private void swap(int i, int j) {
        int tmp = heap[i];
        heap[i] = heap[j];
        heap[j] = tmp;
    }
}
