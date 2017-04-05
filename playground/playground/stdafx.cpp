// stdafx.cpp : source file that includes just the standard includes
// playground.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"
//#include "../common.h"
// TODO: reference any additional headers you need in STDAFX.H
// and not in this file
//
//struct node
//{
//	int d;
//	node *l;
//	node *r;
//	node(int data):d(data),l(NULL),r(NULL){}
//};
//class tree
//{
//public:
//	node *root;
//	tree():root(NULL){}
//	/*********************************/
//	void fromVector(ivector v)
//	{
//		rec(v, 0,v.size()-1, root);
//	}
//	
//	void rec(ivector v, int l, int r, node *n)
//	{
//		if(l>r)
//			return;
//		int m= l+(r-l)/2;
//		n = new node(v[m]);
//		rec(v, l, m-1, n->l);
//		rec(v, m+1, r, n->r);
//	}
//	/*********************************/
//	void fromPreIn(ivector in, ivector pre)
//	{
//		recPreIn(in, pre,0,pre.size(),0, in.size(), root);
//	}
//	
//	void recPreIn(ivector in, ivector pre, int l1, int r1, int l2, int r2, node *n)
//	{
//		int x;
//		n = new node(in[l1]);
//		n->l = new node(pre[(x-l2)/2]);
//		n->r = new node(pre[(r2-x)/2]);
//		recPreIn(in,pre, l1+1, x-l2,  l2 , x-1, n->l);
//		recPreIn(in,pre, x+1 , r1  ,  x+1, r2 , n->l);
//	}
//	
//	void preOrderTraversal(node* n)
//	{
//		if(n==NULL)
//			return;
//		cout<<n->d;
//		preOrderTraversal(n->l);
//		preOrderTraversal(n->r);
//	}
//	void inOrderTraversal(node* n)
//	{
//		if(n==NULL)
//			return;
//		inOrderTraversal(n->l);
//		cout<<n->d;
//		inOrderTraversal(n->r);
//	}
//	
//	node *findMin(node *n)
//	{
//		if(n==NULL)
//			return NULL;
//		while(n->l != NULL)
//			n = n->l;
//		return n;
//	}
//};
