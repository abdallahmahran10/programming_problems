/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
	Date: 3/21/2017
*/

// Includes
#include "../common.h"
// Types
struct TreeLinkNode 
{
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
// Functions
void connect(TreeLinkNode *left, TreeLinkNode *right) 
{
	if(left!=NULL)
	{
		left->next = right;
		connect(left->left, left->right);
		connect(left->right, right->left);
		connect(right->left, right->right);
	}
}

void connect(TreeLinkNode *root) 
{
	connect(root->left, root->right); 
}
