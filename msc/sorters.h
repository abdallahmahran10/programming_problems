/*
Author: Abdallah Mahran
file: sorters.h
desc: implementation of some wel known algorithms 
*/

#ifndef SORTERS_H
#define SORTERS_H
/******************* Includes *******************/
#include <vector>
#include <cstdlib>
/******************* Sorter *******************/
template <typename T>
class Sorter
{
public:
	virtual void sort(std::vector<T> &V)
	{
		if (V.empty())
			return;
		sort(&V[0], V.size());
	}
	virtual void sort(T *A, size_t n) = 0;
	std::vector<T> toVector(T *A, size_t n)
	{
		return std::vector<T>(A, A + n);
	}
};

/******************* Quick Sorter *******************/
template <typename T>
class QuickSorter : public Sorter<T>
{
	int partition(T *A, int s, int e)
	{
		int pivotIdx = e;
		for (int i = e - 1; i >= s; i--)
		{
			if (A[i]> A[pivotIdx])
			{
				int j = i;
				int diff = std::abs(i - pivotIdx);				
				if (diff != 1)
				{
					swap(A[i], A[pivotIdx - 1]);
				}
				swap(A[pivotIdx - 1], A[pivotIdx]);
				pivotIdx --;
			}
		}
		return pivotIdx;
	}
private:
	void quickSort(T *A, int s, int e)
	{
		if (e > s)
		{
			int pivotIdx = partition(A, s, e);
			quickSort(A, s, pivotIdx-1);
			quickSort(A, pivotIdx + 1, e);
		}
	}

public:
	virtual void sort(T *A, size_t n) 
	{
		if (n < 2)
			return;
		quickSort(A, 0, n - 1);
	}
};

/******************* Merge Sorter *******************/
template <typename T>
class MergeSorter : public Sorter<T>
{
private:
	void merge(T *A, int l, int m, int r)
	{
		int ls = m - l;
		int rs = e - m + 1;
		T *L = new T[ls];
		T *L = new T[rs];
		int i;
		for (i = 0; i < ls)
			L[i] = A[l + i];
		for (i = 0; i < rs)
			L[i] = A[m + i + 1];
		int j = 0; 
		i = 0;
		int k = l;
		//
		while (i < ls && j < rs)
		{
			//if ()
		}
	}

	void mergeSort(T *A, int l, int r)
	{
		if (l < r)
		{
			int m = l + (r - l) / 2;
			mergeSort(A, l, m);
			mergeSort(A, m+1, r);
			merge(A, l, m, r);
		}
	}

public:
	virtual void sort(T *A, size_t n) 
	{
		if (n < 2)
			return;
		mergeSort(A, 0, n-1);
	}
};

/******************* Insertion Sorter *******************/
template <typename T>
class InsertionSorter : public Sorter<T>
{
private:
	void insertionSort(T *A, size_t  n)
	{
		for (int i = 1; i < n; i++)
		{
			int tmp = A[i];
			for (int j = 0; j < i; j++)
			{
				if (A[j] >= tmp)
				{
					// Insert the tmp value to be the jth element
					int k = i;
					while (k > j)
					{
						A[k] = A[k - 1];
						k--;
					}
					A[j] = tmp;
					break; 
				}
			}
		}
	}

public:
	virtual void sort(T *A, size_t n) 
	{
		if (n < 2)
			return;
		insertionSort(A, n );
	}
};
#endif //SORTERS_H
