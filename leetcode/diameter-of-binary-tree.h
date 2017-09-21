/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/diameter-of-binary-tree/description/
	Date: 9/21/2017
*/

// Includes
#include "../common.h"
// Types
// Functions
int maxDep(TreeNode* root, int *maxDiam) {
    if(root == NULL)
        return 0;
    int v=root->val;
    int l = maxDep(root->left,maxDiam);
    int r = maxDep(root->right, maxDiam);
    *maxDiam = max(l+r, *maxDiam);
    return max(l, r) + 1;
}
int diameterOfBinaryTree(TreeNode* root) {
    if(root == NULL)
        return 0;
    int maxDiam =0;
    maxDep(root, &maxDiam);
    return maxDiam;
}
