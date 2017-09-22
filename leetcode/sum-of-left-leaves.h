/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/sum-of-left-leaves/description/
	Date: 9/22/2017
*/

// Includes
#include "../common.h"
// Types
// Functions
int sumOfLeftLeaves(TreeNode* root) {
	if(root==NULL)
		return 0;
    int v=0;
	if(root->left != NULL)
		v = (root->left->left == NULL && root->left->right == NULL?root->left->val:0 );
	return v + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}
