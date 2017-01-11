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
struct TreeNode {
	T data;
	TreeNode *leftChild;
	TreeNode *rightChild;
	TreeNode(T d)
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
	static TreeNode<T> *fromPreorderAndInorder(vector<T>& preorder, vector<T>& inorder)
	{
		if (preorder.empty() || inorder.size()!=preorder.size())
			return NULL;
		return buildTree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
	}
	//
	static TreeNode<T> *buildTree(vector<T>& preorder, vector<T>& inorder, int ps, int pe, int is, int ie)
	{
		if(pe<ps)
			return NULL;
		TreeNode<T> *node = new TreeNode<T>(preorder[ps]);
		vector<T>::iterator inOrderStartItr= next(inorder.begin(), is);
		vector<T>::iterator inOrderEndItr= next(inorder.begin(), ie);
		vector<T>::iterator it = find(inOrderStartItr, inOrderEndItr, preorder[ps]);
		if(it == inorder.end())
			return NULL;
		if(pe - ps == 1)
		{
		    if(preorder[ps] == inorder[is])
			    node->rightChild = new TreeNode<T>(preorder[ps + 1]);
			 else
			    node->leftChild = new TreeNode<T>(preorder[ps + 1]);
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
	static TreeNode<T> *fromSortedVector(std::vector<T> &dataVec)
	{
		if (dataVec.empty())
			return NULL;
		TreeNode<T> * rootNode = constructBalancedBT(dataVec, 0, dataVec.size() - 1);
		return rootNode;
	}
	//
	static TreeNode<T> *constructBalancedBT(std::vector<T> &dataVec, int s, int e)
	{
		if (s > e)
			return NULL;
		if (s == e)
			return new TreeNode<T>(dataVec[s]);
		int mid = s + (e - s) / 2;
		TreeNode<T> * node = new TreeNode<T>(dataVec[mid]);
		node->leftChild = constructBalancedBT(dataVec, s, mid - 1);
		node->rightChild = constructBalancedBT(dataVec, mid + 1, e);
		return node;
	}
/*********** Private Members **********/
private:
	TreeNode<T> *mRoot;
	// print preorder traversal
	void preOrderTraversal(TreeNode<T>* node)
	{
		if(node == NULL)
			return;
		std::cout<<node->data<< " "; 
		preOrderTraversal(node->leftChild);
		preOrderTraversal(node->rightChild);
	}
	//
	void inOrderTraversal(TreeNode<T>* node)
	{
		if(node == NULL)
			return;
		inOrderTraversal(node->leftChild);
		std::cout<<node->data<< " "; 
		inOrderTraversal(node->rightChild);
	}
/*********** Public Members **********/
public:
	BST(TreeNode<T> *root) { mRoot = root; }
	BST(){ mRoot = NULL; }
	~BST(){}
	//
	void insert(TreeNode<T> *node)
	{

		TreeNode<T> *slider = mRoot;
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
		insert(new TreeNode<T>(data));
	}
	//
	TreeNode<T> *search(T data)
	{
		TreeNode<T> *slider = mRoot;
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
};

#endif //BST_H
