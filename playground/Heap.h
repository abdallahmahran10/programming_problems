// A C++ program to demonstrate common Binary Heap Operations
#include<iostream>
#include<climits>
using namespace std;
 
// Prototype of a utility function to swap two integers
void swap(int *x, int *y);
 
// A class for Min Heap
class MinHeap
{
    int *heapHead; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:
    // Constructor
	MinHeap(int c): capacity(c),heap_size(0)
	{
		heapHead = new int[c];
	}
	void swap(int i, int j){
		int tmp = heapHead [i];
		heapHead [i] = heapHead [j];
		heapHead [j] = tmp;
	}
    // to heapify a subtree with root at given index
    void MinHeapify(int i)
	{
		int l = left(i);
		int r = right(i);
		int minIdx = i;
		if(l<heap_size && heapHead[l] < heapHead[i])
			minIdx = l;
		if(r<heap_size && heapHead[r] < heapHead[i])
			minIdx = r;
		if(minIdx !=i)
		{
			swap(i, minIdx);
			MinHeapify(minIdx);
		}
	}
 
	int parent(int i){return (i -1) / 2;}
 
    // to get index of left child of node at index i
	int left(int i){return 2*i +1;}
 
    // to get index of right child of node at index i
    int right(int i) {return 2*i +2;}
    // to extract the root which is the minimum element
    int extractMin()
	{
		int ret = heapHead[0];
		heapHead[0] = heapHead[--heap_size];
		MinHeapify(0);
		return ret;
	}
 
    // Decreases key value of key at index i to new_val
    void decreaseKey(int i, int new_val)
	{
		heapHead[i] = new_val;
		while(i>0 && heapHead[parent(i)] > heapHead[i])
		{
			swap(i, parent(i));
			i = parent(i);
		}
	}
 
    // Returns the minimum key (key at root) from min heap
	int getMin() {return heapHead[0];}
 
    // Deletes a key stored at index i
    void deleteKey(int i)
	{
		decreaseKey(i, INT_MIN);
		extractMin();
	}
 
    // Inserts a new key 'k'
    void insertKey(int k)
	{
		if (heap_size == capacity)
		{
			cout << "\nOverflow: Could not insertKey\n";
			return;
		}
		heap_size++;
		int i = heap_size - 1;
		harr[i] = k;
 
		// Fix the min heap property if it is violated
		while (i != 0 && harr[parent(i)] > harr[i])
		{
		   swap(&harr[i], &harr[parent(i)]);
		   i = parent(i);
		}	
	}
};
