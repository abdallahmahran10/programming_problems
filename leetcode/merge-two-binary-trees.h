/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/merge-two-binary-trees/description/
	Date: 8/30/2017
*/

// Includes
#include "../common.h"
// Types
// Functions
  TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
      // NOTE: the method will override the merged tree in t1
      //  Therefore the value of the input t1 will be changed when calling this method
      if(t1==NULL)
      return t2;
      if(t2==NULL)
          return t1;
      t1->val = t1->val + t2->val;
      t1->left = mergeTrees(t1->left , t2->left);
      t1->right = mergeTrees(t1->right , t2->right);
      return t1;
  }
// Test cases
