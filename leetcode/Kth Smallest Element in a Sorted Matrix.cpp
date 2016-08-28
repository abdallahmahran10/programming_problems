#include "common.h" // my defined macros

// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

int kthSmallest(vector<vector<int>>& matrix, int k) {
        
	priority_queue<int> heap;
	int n=matrix.size();
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			heap.push(matrix[i][j]);
		}
	}
	//print_queue(heap);
	int rk= (n*n) - k ;
	cout<<"rk:"<<rk<<endl;
	while(rk--)
	{
		heap.pop();
	}
	//print_queue(heap);
	return heap.top();
}