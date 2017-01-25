/*
* Author: Abdallah Mahran
* file: BST.h
*/
#ifndef BST_H
#define BST_H
/******************* Includes *******************/
#include <vector>
#include <iostream>

/******************* Types *******************/
template <typename T>
struct Node {
	T data;
	Node *leftChild;
	Node *rightChild;
	Node(T d)
	{ 
		data = d;
		rightChild = leftChild = NULL;
	}
};

/******************* BST Cass *******************/
template <typename T>
class BST
{
/*********** Static Members **********/
public: 
	static BST CreateBST(T *dataArr,  int len, bool sorted = true)
	{
		std::vector<T> dataVec(dataArr, dataArr + len);
		if (!sorted)
			std::sort(dataVec.begin(), dataVec.end());
		BST<T> bst(fromSortedVector(dataVec));
		return bst;
	}
	//
	static BST CreateBST(std::vector<T> &dataVec, bool sorted = true)
	{
		if (!sorted)
			std::sort(dataVec.begin(), dataVec.end());
		BST<T> bst(fromSortedVector(dataVec));
		return bst;
	}
	//	
	static BST CreateBSTFromPreorderAndInorder(vector<T>& preorder, vector<T>& inorder)
	{
		BST<T> bst(fromPreorderAndInorder(preorder, inorder));
		return bst;
	}
private:
	static Node<T> *fromPreorderAndInorder(vector<T>& preorder, vector<T>& inorder)
	{
		if (preorder.empty() || inorder.size()!=preorder.size())
			return NULL;
		return buildTree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
	}
	//
	static Node<T> *buildTree(vector<T>& preorder, vector<T>& inorder, int ps, int pe, int is, int ie)
	{
		if(pe<ps)
			return NULL;
		Node<T> *node = new Node<T>(preorder[ps]);
		vector<T>::iterator inOrderStartItr= next(inorder.begin(), is);
		vector<T>::iterator inOrderEndItr= next(inorder.begin(), ie);
		vector<T>::iterator it = find(inOrderStartItr, inOrderEndItr, preorder[ps]);
		if(it == inorder.end())
			return NULL;
		if(pe - ps == 1)
		{
		    if(preorder[ps] == inorder[is])
			    node->rightChild = new Node<T>(preorder[ps + 1]);
			 else
			    node->leftChild = new Node<T>(preorder[ps + 1]);
			return node;
		}
		else if(pe - ps == 0)
			return node;
		//
		int idx = it - inOrderStartItr;
		node->leftChild = buildTree(preorder, inorder, ps+1 ,  ps + idx, is,  is +  idx-1);
		node->rightChild = buildTree(preorder, inorder,ps + idx+1,  pe, is + idx+1, ie);
		return node;
	}

	//
	static Node<T> *fromSortedVector(std::vector<T> &dataVec)
	{
		if (dataVec.empty())
			return NULL;
		Node<T> * rootNode = constructBalancedBT(dataVec, 0, dataVec.size() - 1);
		return rootNode;
	}
	//
	static Node<T> *constructBalancedBT(std::vector<T> &dataVec, int s, int e)
	{
		if (s > e)
			return NULL;
		if (s == e)
			return new Node<T>(dataVec[s]);
		int mid = s + (e - s) / 2;
		Node<T> * node = new Node<T>(dataVec[mid]);
		node->leftChild = constructBalancedBT(dataVec, s, mid - 1);
		node->rightChild = constructBalancedBT(dataVec, mid + 1, e);
		return node;
	}
/*********** Private Members **********/
private:
	Node<T> *mRoot;
	// print preorder traversal
	void preOrderTraversal(Node<T>* node)
	{
		if(node == NULL)
			return;
		std::cout<<node->data<< " "; 
		preOrderTraversal(node->leftChild);
		preOrderTraversal(node->rightChild);
	}
	//
	void inOrderTraversal(Node<T>* node)
	{
		if(node == NULL)
			return;
		inOrderTraversal(node->leftChild);
		std::cout<<node->data<< " "; 
		inOrderTraversal(node->rightChild);
	}
	//
	Node<T> *findMin(Node<T> *node)
	{
		if(node == NULL)
			return NULL;
		while(node->leftChild != NULL)
			node = node->leftChild;
		return node;
	}
	//
	Node<T> *deleteNodeUtil(Node<T> *node)
	{
		if(node->leftChild == NULL || node->rightChild == NULL )
		{
			// if has one children
			if(node->leftChild != NULL)
			{
				Node<T> *tmp = node;
				node = node->leftChild;
				delete tmp; 
				tmp = NULL;
			} 
			else if(node->rightChild != NULL )
			{
				Node<T> *tmp = node;
				node = node->rightChild;
				delete tmp;
				tmp = NULL;
			} 
			else
			{		// if has no children just free memory
				delete node;
				node = NULL;
			}
		}
		// if has two children, find min in right and copy it to "node" and delete it
		else
		{
			int min=0;
			Node<T> *tmp = findMin(node->rightChild);
			node->data = tmp->data;
			node->rightChild = deleteNode(node->rightChild, tmp->data);
		}
		return node;
	}
	//
	Node<T> *deleteNode(Node<T> *node, T data)
	{
		if(node == NULL)
			return NULL;
		if(data < node->data)
			node->leftChild = deleteNode(node->leftChild, data);
		else if(data > node->data)
			node->rightChild = deleteNode(node->rightChild, data);
		else // found the node
		{
			return deleteNodeUtil(node);
		}
		return node;
	}
/*********** Public Members **********/
public:
	BST(Node<T> *root) 
	{ 
		mRoot = root; 
	}
	BST(){ mRoot = NULL; }
	~BST(){}
	//
	void insert(Node<T> *node)
	{

		Node<T> *slider = mRoot;
		while (slider != NULL)
		{
			if (node->data >= slider->data)
			{
				if (slider->rightChild == NULL)
				{
					slider->rightChild = node;
					break;
				}
				slider = slider->rightChild;
			}
			else if (node->data < slider->data)
			{
				if (slider->leftChild == NULL)
				{
					slider->leftChild = node;
					break;
				}
				slider = slider->leftChild;
			}
		}
	}
	//
	void insert(T data)
	{
		insert(new Node<T>(data));
	}
	//
	Node<T> *search(T data)
	{
		Node<T> *slider = mRoot;
		while (slider != NULL)
		{
			if (data == slider->data)
				return slider;
			else if (data > slider->data)
				slider = slider->rightChild;
			else if (data < slider->data)
				slider = slider->leftChild;
		}
		return NULL;
	}
	//
	void preOrderPrint()
	{
		preOrderTraversal(mRoot);
		std::cout<<std::endl;
	}
	//
	void inOrderPrint()
	{
		inOrderTraversal(mRoot);
		std::cout<<std::endl;
	}
	//
	void deleteNode(T data)
	{
		deleteNode(mRoot, data);
	}
	//
	int getHeight(Node<T> *node)
	{
		if(node==NULL)
			return -1;
		return max(getHeight(node->leftChild), getHeight(node->rightChild)) +1;
	}
	//
	int getHeight(T data)
	{
		return getHeight(search(data));
	}
};

#endif //BST_H

/*

/////////////////////////////////////////////////////
int minDepth(TreeNode* root) {
	if(root == NULL)
		return 0;
	if(root->left == NULL) 
		return 1 + minDepth(root->right);
	if(root->right == NULL) 
		return 1 + minDepth(root->left);
	return min(minDepth(root->left), minDepth(root->right)) + 1;
}
/////////////////////////////////////////////////////
int maxDepth(TreeNode* root) {
	if(root == NULL)
		return 0;
	if(root->left == NULL) 
		return 1 + maxDepth(root->right);
	if(root->right == NULL) 
		return 1 + maxDepth(root->left);
	return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
/////////////////////////////////////////////////////
vector<vector<int>> res;
void buildLevelsVector(TreeNode* node, int depth)
{
	if(node == NULL)
		return ;
	if(res.size() == depth)
		res.push_back(vector<int>());
	res[depth].push_back(node->val);
	buildLevelsVector(node->left, depth + 1);
	buildLevelsVector(node->right, depth + 1);
}
//
vector<vector<int>> levelOrder(TreeNode* root) {
	buildLevelsVector(root, 0);
	return res;
}
/////////////////////////////////////////////////////
int balanced(TreeNode* subTree)
{
	if(subTree == NULL)
		return 0;
	int lh = balanced(subTree->left);
	if(lh == -1)
		return -1;
	int rh = balanced(subTree->right);
	if(rh == -1)
		return -1;
	int diff = abs(lh-rh);
	if(diff>1)
		return -1;
	return 1 + max(lh, rh);
}

bool isBalanced(TreeNode* root) {
	
	return balanced(root) != -1;
}
/////////////////////////////
*/