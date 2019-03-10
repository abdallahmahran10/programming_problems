package com.mahran.msc;

public class Searchers {
    /////////////////// Binary Search
    public static int search(int[] arr, int v) {
        int s = 0, e = arr.length - 1;
        while (e >= s) {
            int mid = (e - s) /2 + s;
            if (arr[mid] == v) {
                return mid;
            }
            if (arr[mid] > v) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return -1;
    }
    //
    public static int searchRec(int[] arr, int v) {
        return searchRec(arr, v, 0, arr.length - 1);
    }

    private static int searchRec(int[] arr, int v, int s, int e) {
        if (e < s) {
            return -1;
        }
        int mid = (e - s) /2 + s;
        if (arr[mid] == v) {
            return mid;
        }
        if (arr[mid] > v) {
            return searchRec(arr, v, s, mid -1);
        } else {
            return searchRec(arr, v, mid + 1, e);
        }
    }
    /////////////////// First Occurrences
    public static int  firstOccurrence(int[] arr, int v) {
        int s = 0, e = arr.length - 1;
        int f = -1;
        while (e >= s) {
            int mid = (e - s) /2 + s;
            if (arr[mid] == v) {
                f = mid;
                e = mid - 1;
            } else if (arr[mid] > v) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return f;
    }
    /////////////////// Last Occurrences
    public static int  lastOccurrence(int[] arr, int v) {
        int s = 0, e = arr.length - 1;
        int l = -1;
        while (e >= s) {
            int mid = (e - s) /2 + s;
            if (arr[mid] == v) {
                l = mid;
                s = mid + 1;
            } else if (arr[mid] > v) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return l;
    }
    /////////////////// Count Occurrences
    public static int countOccurrences0(int[] arr, int v) {
        int f = firstOccurrence(arr, v);
        if (f == -1) {
            return 0;
        } else {
            return lastOccurrence(arr, v) - f + 1;
        }
    }
    // my solution
    public static int countOccurrences1(int[] arr, int v) {
        return countOccurrences1(arr, v, 0, arr.length - 1);
    }

    private static int countOccurrences1(int[] arr, int v, int s, int e) {
        if (e < s) {
            return 0;
        }
        int mid = (e - s) /2 + s;
        if (arr[mid] == v) {
            return countOccurrences1(arr, v, s, mid -1) + countOccurrences1(arr, v, mid +1, e) + 1;
        } else if (arr[mid] > v) {
            return countOccurrences1(arr, v, s, mid -1);
        } else {
            return countOccurrences1(arr, v, mid +1, e);
        }
    }
    /////////////////// Count Rotation
    public static int countRotation0(int[] arr) {
        if (arr.length < 1) {
            return 0;
        }
        int n = arr.length;
        int low = 0, high = n - 1;
        while (low <= high) {
            if (arr[low] <= arr[high]) {
                return low;
            }
            int mid = (high + low) /2;
            int next = (mid + 1) % n;
            int prev = (mid + n - 1) % n;
            if (arr[mid] <= arr[next] && arr[mid] <= arr[prev]) {
                return mid;
            } else if (arr[mid] <= arr[high]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return -1;
    }
    // my solution
    public static int countRotation1(int[] arr) {
        return countRotation1(arr, 1, arr.length - 1);
    }

    private static int countRotation1(int[] arr, int s, int e) {
        if (e < s) {
            return 0;
        }
        int mid = (e - s) /2 + s;
        if (arr[mid] < arr[mid -1]) {
            return mid;
        }
        int lRotation = countRotation1(arr,  s, mid - 1);
        if (lRotation > 0) {
            return lRotation;
        } else {
            return countRotation1(arr,  mid + 1, e);
        }
    }
    // search in circular array
    public static int searchInCircular(int[] arr, int v) {
        // TODO: implement it
        return -1;
    }
}
