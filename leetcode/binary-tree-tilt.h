 /*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/binary-tree-tilt/description/
	Date: 9/19/2017
*/

// Includes
#include "../common.h"
// Types
// Functions
int preorder(TreeNode* node, int *tilt)
    {
        if(node == NULL)
            return 0;
        int lSum = preorder(node->left, tilt);
        int rSum = preorder(node->right, tilt);
        *tilt = *tilt + abs(lSum - rSum);
        return node->val + lSum + rSum;
    }

    int findTilt(TreeNode* root) {
        int tilt=0;
        preorder(root, &tilt);
        return tilt;
    }
