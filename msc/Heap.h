// Binary Heap
#include<iostream>
#include<climits>

/*
Operations on Min Heap:
1) getMini(): It returns the root element of Min Heap. Time Complexity of this operation is O(1).
2) extractMin(): Removes the minimum element from Min Heap. Time Complexity of this Operation is O(Logn) 
	as this operation needs to maintain the heap property (by calling heapify()) after removing root.
3) decreaseKey(): Decreases value of key. Time complexity of this operation is O(Logn). 
	If the decreases key value of a node is greater than parent of the node, then we don’t need to do anything. Otherwise, 
	we need to traverse up to fix the violated heap property.
4) insert(): Inserting a new key takes O(Logn) time. We add a new key at the end of the tree. IF new key is greater than its parent, 
	then we don’t need to do anything. Otherwise, we need to traverse up to fix the violated heap property.
5) delete(): Deleting a key also takes O(Logn) time. We replace the key to be deleted with minum infinite by calling decreaseKey(). 
	After decreaseKey(), the minus infinite value must reach root, so we call extractMin() to remove key.
*/
template<typename T>
class Heap
{
protected:
	T *heapArray;
	int capacity;
	int heapSize;
public:
	Heap(int n):capacity(n), heapSize(0)
	{
		heapArray = new T[n];
	}
	//
	T getRoot()
	{
		return heapArray[0];
	}
	//
	void insert(T elm);
};

template<typename T>
class MaxHeap : public Heap<T>
{
public:
	MaxHeap(int n) : Heap<T>(n)
	{}

};

template<typename T>
class MinHeap : public Heap<T>
{
public:
	MinHeap(int n) : Heap<T>(n)
	{}
};
