/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/maximum-width-of-binary-tree
	Date: 9/21/2017
*/
// Includes
#include "../common.h"
// Types
// Functions
void lvlOrder(TreeNode* node, vector<  pair < int,int >  > & lvl, int id,
		int l) {
	if (node == NULL)
		return;
	if (lvl.size() == l)
		lvl.push_back(make_pair(id, id));
	else
	{
		lvl[l].first = min(lvl[l].first, id);
		lvl[l].second = max(lvl[l].second, id);
	}
	lvlOrder(node->left, lvl, id*2-1, l+1);
	lvlOrder(node->right, lvl, id*2, l+1);
}

int widthOfBinaryTree(TreeNode* root) {
	if (root == NULL)
		return 0;
	if (root->left == NULL & root->right == NULL)
		return 1;
	vector<  pair < int,int >  > lvl;
	lvl.push_back(make_pair(1, 1));
	lvlOrder(root, lvl, 1, 0);
	int maxWidth = 0;
	for (int i = 0; i < lvl.size(); i++)
		maxWidth = max(maxWidth, lvl[i].second - lvl[i].first + 1);

	return maxWidth;
}
