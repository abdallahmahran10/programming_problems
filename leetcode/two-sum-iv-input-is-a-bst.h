/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
	Date: 9/22/2017
*/

// Includes
#include "../common.h"
// Types
// Functions
bool findTarget(TreeNode* root, int k) {
    unordered_set<int> hs;
	stack<TreeNode *> st;
	st.push(root);
	while(!st.empty())
	{
		TreeNode *node = st.top();
		if(hs.find(k-node->val) != hs.end())
			return true;
		st.pop();
		hs.insert(node->val);
		if(node->left != NULL)
			st.push(node->left);
		if(node->right != NULL)
			st.push(node->right);
	}
	return false;
}
