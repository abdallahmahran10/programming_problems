/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/maximum-binary-tree/description/
	Date: 9/24/2017
*/

// Includes
#include "../common.h"
// Types
// Functions
int partition(vector<int> v, int s, int e)
{
    int pIndx = s;
    int max=v[s];
    for(int i=s+1; i<=e; ++i)
        pIndx = v[pIndx]<v[i]? i:pIndx;
    return pIndx;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums, int s, int e) 
{
    if (s <= e)
    {
        int pivotIdx = partition(nums, s, e);
        TreeNode *newRoot = new TreeNode(nums[pivotIdx]);
        newRoot->left = constructMaximumBinaryTree(nums, s, pivotIdx-1);
        newRoot->right = constructMaximumBinaryTree(nums, pivotIdx + 1, e);
        return newRoot;
    }
    return NULL;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
{
    return constructMaximumBinaryTree(nums, 0, nums.size()-1);
}
