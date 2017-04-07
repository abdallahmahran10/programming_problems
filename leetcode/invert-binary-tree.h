/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/invert-binary-tree/#/description
	Date: 04/07/2017
*/

// Includes
#include "../common.h"
// Types
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
// Functions
void swap(TreeNode** n1, TreeNode** n2)
{
  TreeNode* n = *n2;
  *n2 = *n1;
  *n1 = n;
}

void invertChildren(TreeNode* node)
{
    if(node == NULL)
        return ;
  swap(&(node->left), &(node->right));
  invertChildren(node->left);
  invertChildren(node->right);	
}

TreeNode* invertTree(TreeNode* root) {
    if(root == NULL)
        return NULL;
  invertChildren(root);
  return root;
}
// Test cases
