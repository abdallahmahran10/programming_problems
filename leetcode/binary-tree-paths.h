/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/binary-tree-paths/
	Date: 12/13/2016
*/

// Includes
#include "common.h"
// Types
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// Functions
void addValToPath(string& path, int val)
{
	if (path.length()>0)
		path += "->" + to_string(val);
	else
		path = to_string(val);
}
//
void parseTree(TreeNode* root, vector<string>& paths, string path = "")
{
	if (root == NULL)
		return;
	//
	addValToPath(path, root->val);
	if (root->right == NULL && root->left == NULL)
	{
		paths.push_back(path);
		return;
	}
	//
	parseTree(root->left, paths, path);
	parseTree(root->right, paths, path);
}
//
vector<string> binaryTreePaths(TreeNode* root) {
	vector<string> paths;
	if (root == NULL)
		return paths;
	parseTree(root, paths);
	return paths;
}


// Test cases

void testCase0()
{
	TreeNode node(1);
	node.left = new TreeNode(2);
	node.left->right = new TreeNode(5);
	node.right = new TreeNode(3);
	printStringVector(binaryTreePaths(&node));
}

void testCase1()
{
	TreeNode node(1);
	node.left = new TreeNode(2);
	node.left->right = new TreeNode(5);
	node.right = new TreeNode(3);
	node.right->left = new TreeNode(6);
	node.right->right = new TreeNode(7);
	printStringVector(binaryTreePaths(&node));
}

void testCase2()
{
	TreeNode node(1);
	printStringVector(binaryTreePaths(&node));
}

void testCase3()
{
	TreeNode node(1);
	node.left = new TreeNode(2);

	printStringVector(binaryTreePaths(&node));
}
