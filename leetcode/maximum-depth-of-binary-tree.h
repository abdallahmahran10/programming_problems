/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
	Date: 9/16/2017
*/

// Includes
#include "../common.h"
// Types
// Functions
// solution 1
void dep(TreeNode* node, int *depth, int cd)
{
	if(node == NULL)
		return;
	if(cd == *depth)
		*depth++;
	dep(node->left, depth, cd+1);
	dep(node->right, depth, cd+1);
}

int maxDepth(TreeNode* root) 
{
	if(root == NULL)
		return 0;
	int depth = 1;
	dep(root, &depth, 0);
	return depth;
}
// solution 2
int maxDepth(TreeNode* root) {
  if(root == NULL)
    return 0;
  if(root->left == NULL) 
    return 1 + maxDepth(root->right);
  if(root->right == NULL) 
    return 1 + maxDepth(root->left);
  return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
