package com.mahran.msc;

public class Sorters {
    /////// Selection Sort O(n2)
    public static void selectionSort(int[] arr) {
        for (int i = 0; i < arr.length - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[j] < arr[minIdx]) {
                    minIdx = j;
                }
            }
            if (minIdx != i) {
                swap(arr, i, minIdx);
            }
        }
    }
    /////// Bubble Sort O(n2)
    public static void bubbleSort(int[] arr) {
        boolean sorted;
        for (int i = arr.length - 1; i >= 0; i--) {
            sorted = true;
            for (int j = 0; j < i; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr, j, j + 1);
                    sorted = false;
                }
            }
            if (sorted) {
                return;
            }

        }
    }
    /////// Insertion Sort
    public static void insertionSort(int[] arr) {
        for (int i = 1; i < arr.length; i++) {
            int key = arr[i];
            int j = i -1;
            while (j >= 0 && key < arr[j]) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j+1] = key;

        }
    }
    /////// Merge Sort
    public static void mergeSort(int[] arr) {
        if (arr.length < 2) {
            return;
        }
        int mid = arr.length / 2;
        int[] left = slice(arr, 0, mid - 1);
        int[] right = slice(arr, mid, arr.length - 1);

        mergeSort(left);
        mergeSort(right);
        merge(arr, left, right);
    }

    private static void merge(int[] arr, int[] left, int[] right) {
        int i = 0, j = 0;
        int arrIdx = 0;
        while (i < left.length && j < right.length) {
            if (left[i] < right[j]) {
                arr[arrIdx++] = left[i++];
            } else if (right[j] < left[i]) {
                arr[arrIdx++] = right[j++];
            } else {
                arr[arrIdx++] = left[i++];
                arr[arrIdx++] = right[j++];
            }
        }
        while (i < left.length) {
            arr[arrIdx++] = left[i++];
        }
        while (j < right.length) {
            arr[arrIdx++] = right[j++];
        }
    }

    private static int[] slice(int[] arr, int s, int e) {
        if (e <= s) {
            return new int[] {arr[s]};
        }
        int[] sliced = new int[e - s + 1];
        int j = 0;
        for (int i = s; i <= e; i++) {
            sliced[j++] = arr[i];
        }
        return sliced;
    }

    /////// Quick Sort
    public static void quickSort(int[] arr) {
        if (arr.length < 2) {
            return;
        }
        quickSort(arr, 0 , arr.length - 1);
    }

    private static void quickSort(int[] arr, int s, int e) {
        int p = partition(arr, s, e);
        if (s < e) {
            quickSort(arr, s, p -1);
            quickSort(arr, p + 1, e);
        }
    }

    private static int partition(int[] arr, int s, int e) {
        int p = e;
        for (int i= e - 1; i >= s; i--){
            if (arr[i] > arr[p]) {
                if (p - i != 1) {
                    swap(arr, i, p -1 );
                }
                swap(arr, p, p -1 );
                 p--;
            }
        }
        return p;
    }

    /////////////////////
    private static void swap(int[] arr, int i, int j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}
