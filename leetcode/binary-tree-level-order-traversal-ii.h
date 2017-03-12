/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/?tab=Description
	Date: 3/12/2017
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

void levelOrderBottom(TreeNode* root, vector<vector<int>> &result, int level) {
  if(root == NULL)
    return;
  if(level == result.size())
      result.push_back(vector<int>());
  result[level].push_back(root->val);
  levelOrderBottom(root->left, result, level +1);
  levelOrderBottom(root->right, result, level +1);
}

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> result;
    levelOrderBottom(root, result, 0);
    reverse(result.begin(), result.end());
    return result;
}
