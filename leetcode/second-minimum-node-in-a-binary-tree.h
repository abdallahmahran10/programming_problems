/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/description/
	Date:9/15/2017 
*/

// Includes
#include "../common.h"
// Types
// Functions

void traverse(TreeNode* node , int *val)
{
	if(node == NULL)
		return;
	if(node->val > *val)
	{
		*val = node->val;
		return;
	}
	int lVal = *val;
	traverse(node->left, &lVal);
	int rVal = *val;
	traverse(node->left, &rVal);
	*val = *val == lVal || *val == rVal? max(lVal, rVal): min(lVal , rVal);
}

int findSecondMinimumValue(TreeNode* root) {
	int val=root->val;
	traverse(root, &val);
	return val;
}

// Test cases

void testCase()
{
	TreeNode* root=new TreeNode(2);
	root->left =new TreeNode(2);	
	root->left->left=new TreeNode(2);	
	root->left->right=new TreeNode(3);	
	root->left->left->left=new TreeNode(5);	
	root->left->left->right=new TreeNode(3);
	
	root->right=new TreeNode(2);	
	root->right->left=new TreeNode(7);	
	root->right->right=new TreeNode(7);	
	cout<<findSecondMinimumValue(root)<<endl;
	cout<<"done"<<endl; 
}
