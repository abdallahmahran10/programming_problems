// playground.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "../common.h" // my defined macros
#include "BST.h"
#include "Graph.h"
#include "Trie.h"
#include "Queue.h"
#include "Heap.h"
#include "sorters.h"
#include "tryIt.h"

//#include "MaximumAbsoluteDifference.h"
/////////////////////uva problems template /////////////////////
//12356 - Army Buddies
int uva12356()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);        
#endif
	// Your code is here //////////////////////////
	
	///////////////////////////////////////////////
#ifdef LOCAL
	fclose (stdout);
#endif
	return 0;
}
///////////////////////
void Main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);        
#endif
	// Implmentation //////////////////////////////
	
	///////////////////////////////////////////////
#ifdef LOCAL
	fclose (stdout);
#endif
}
/*
Input:
      1
     / \
    2   5
   / 
  3 
 / \
4   6
Output:
2
[["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
*/

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

int getLevel(TreeNode* node, int l)
{
	if(node == NULL)
		return 0;
	
	return 1 + max(getLevel(node->left, l+1), getLevel(node->right, l+1));
}
void buildMatrix(TreeNode* node, vector<vector<string>> &matrix, int d, int l, int r)
{
	matrix[d][(l + r) / 2] = to_string(node->val);
	buildMatrix(node->left, matrix, d+1, l , (l + r) / 2);
	buildMatrix(node->right, matrix, d+1, (l + r + 1) / 2, r);
}

vector<vector<string>> printTree(TreeNode* root) {
	int d=getLevel(root, 0);
	vector<vector<string>> matrix(d, vector<string>(pow(2, d)-1, ""));
	buildMatrix(root, matrix, 0, 0, d);
	return matrix;
}

int sumOfLeftLeaves(TreeNode* root) {
	if(root==NULL )
		return 0;
	if(root->left == NULL)
		return root->val;
	return 	sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}

#include "test.h"
/*
[["","","","1","","",""]
["","2","","","","3",""]
["4","","5","","6","",""]]
*/
void testCase()
{
	TreeNode* root=new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(4);
//	root->left->right = new TreeNode(5);
	
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(6);
	printTree(root);
	//root->right->right = new TreeNode(1);
	cout<<"done"<<endl; 
}

//////////////////////////////////////////////////////////////////////  0 1 1 2 3 5 8 13 21 34
int _tmain(int argc, _TCHAR* argv[])
{
	testCase();
	system("pause");
}
