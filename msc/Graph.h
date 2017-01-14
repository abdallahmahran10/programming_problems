/*
* Author: Abdallah Mahran
* File: Graph.h
* Disc: Graph implmentation
*/
#ifndef GRAPH_H
#define GRAPH_H
/******************* Includes *******************/
#include <vector>
#include <stack>
/******************* Types *******************/

/********** AdjacentList **********/
template<typename T>
class GraphNode
{
public:
	T data;
	GraphNode *next;
	GraphNode(T d):data(d), next(NULL){}
	~GraphNode(){}
};
/********** AdjacentList **********/
template<typename T>
class AdjacentList
{
public:
	GraphNode<T> *head;
	std::stack<GraphNode<T>*> visited; 
	//
	AdjacentList():head(NULL){}
	AdjacentList(GraphNode<T> *h):head(h){}
	~AdjacentList()
	{
		//if(this->head!=NULL)
		//{
		//	delete head;
		//}
	}
	
	void addTail(GraphNode<T> *node)
	{
		if(head == NULL)
		{
			head = node;
			return;
		}
		GraphNode<T> *slider = head;
		while(slider->next != NULL)
			slider = slider->next;
		slider->next = node;
	}
};
/******************* Graph Cass *******************/
template<typename T>
class Graph
{
private:
	std::vector<AdjacentList<T>> adjListsVector;

	size_t v;
	bool addEdge(size_t node1Idx, size_t node2Idx)
	{
		adjListsVector[node1Idx].addTail(new GraphNode<T>(adjListsVector[node2Idx].head->data));	
		adjListsVector[node2Idx].addTail(new GraphNode<T>(adjListsVector[node1Idx].head->data));
		return true;
	}

public:
	Graph():v(0){}
	~Graph(){}
	//
	size_t getSize() {return v;}
	//
	void addNode(T data)
	{
		AdjacentList<T> ver(new GraphNode<T>(data));
		adjListsVector.push_back(ver);
		v++;
	}
	//
	bool addEdgeByNodesIdx(size_t node1Idx, size_t node2Idx)
	{
		if(node1Idx >= v || node2Idx >= v )
			return false;
		return addEdge(node1Idx, node2Idx);
	}
	//
	bool addEdgeByNodesData(T node1Data, T node2Data)
	{
		int node1Idx = getNodeIdx(node1Data);
		int node2Idx= getNodeIdx(node2Data);
		if(node1Idx <0 || node2Idx < 0 )
			return false;
		return addEdgeByNodesIdx(node1Idx, node2Idx);
	}
	//
	int getNodeIdx(T nodeData)
	{
		for(int i=0; i<v; i++)
			if(adjListsVector[i].head->data == nodeData)
				return i;
		return -1;
	}

};
#endif //GRAPH_H
