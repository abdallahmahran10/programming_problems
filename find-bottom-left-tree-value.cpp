
/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/find-bottom-left-tree-value/description/
	Date: 9/25/2017
*/

// Includes
#include "../common.h"
// Types
// Functions
void orderTraverse(TreeNode* node, pair<int, int> &levelNodeValuePair, int currLevel) {
	if(node == NULL)
		return;
	if(levelNodeValuePair.first < currLevel)
	{
		levelNodeValuePair.first = currLevel;
		levelNodeValuePair.second = node->val;
	}
	orderTraverse(node->left, levelNodeValuePair, currLevel + 1);
	orderTraverse(node->right, levelNodeValuePair, currLevel + 1);
}
int findBottomLeftValue(TreeNode* root) {
	pair<int, int> levelNodeValuePair;
	levelNodeValuePair.first = 0;
	levelNodeValuePair.second= root->val;
	orderTraverse(root, levelNodeValuePair, 0);
	return levelNodeValuePair.second;
}
