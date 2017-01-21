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
struct GraphNode
{
	T data;
	vector<int> adjecentIndexes;
	GraphNode(T d):data(d){}
	GraphNode(){}
	~GraphNode(){}
};

/******************* Graph Cass *******************/
template<typename T>
class Graph
{
private:
	std::vector<GraphNode<T>> graphVertices;
	size_t V;
	//
	bool addEdge(size_t node1Idx, size_t node2Idx)
	{
		
		return true;
	}
public:
	Graph():V(0){}
	Graph(size_t v){
		V =0;
		for(size_t i=0; i<v; i++)
			addNode(i);		
	}
	~Graph(){}
	//
	size_t getSize() {return v;}
	//
	void addNode(T data)
	{
		 graphVertices.push_back(GraphNode<T>(data));
		 V++;
	}
	//
	bool addEdgeByNodesIdx(size_t node1Idx, size_t node2Idx)
	{
		if(node1Idx>=V || node2Idx>=V)
			return false;
		graphVertices[node1Idx].adjecentIndexes.push_back(node2Idx);
		graphVertices[node2Idx].adjecentIndexes.push_back(node1Idx);
		return true;
	}
	//
	bool addEdgeByNodesData(T node1Data, T node2Data)
	{
		int node1Idx= getNodeIdx(node1Data);
		int node2Idx= getNodeIdx(node2Data);
		if(node1Idx == -1 || node2Idx == -1)
			return false;
		return addEdgeByNodesIdx(node1Idx, node2Idx);
	}
	//
	int getNodeIdx(T nodeData)
	{
		for(int i=0; i<V; i++)
			if(graphVertices[i].data == nodeData)
				return i;
		return -1;
	}
	//
	void depthFirstTraversal() 
	{
		stack<int> indexes;
		bool *visited = new bool[V]();
		int currentVertex = 0;
		visited[0] = true;
		cout<< graphVertices[0].data << " ";
		indexes.push(0);
		do{
			currentVertex = indexes.top();
			indexes.pop();
			for(int i=0; i<graphVertices[currentVertex].adjecentIndexes.size(); i++)
			{
				int idx = graphVertices[currentVertex].adjecentIndexes[i];
				if(visited[idx])
					continue;
				else{
					visited[idx] = true;
					cout<< graphVertices[idx].data << " ";
					indexes.push(idx);
				}
			}
		}while(!indexes.empty());
	}
	//
	void breadthFirstTraversal() 
	{ 
		breadthFirstTraversal(0); 
	}
	//
	void breadthFirstTraversal(size_t s) 
	{
		queue<int> indexes;
		bool *visited = new bool[V]();
		int currentVertex = 0;
		visited[0] = true;
		cout<< graphVertices[0].data << " ";
		indexes.push(s);
		do{
			currentVertex = indexes.front();
			indexes.pop();
			for(int i=0; i<graphVertices[currentVertex].adjecentIndexes.size(); i++)
			{
				int idx = graphVertices[currentVertex].adjecentIndexes[i];
				if(visited[idx])
					continue;
				else{
					visited[idx] = true;
					cout<< graphVertices[idx].data << " ";
					indexes.push(idx);
				}
			}
		}while(!indexes.empty());
	}
	//
	bool isPathExists(int i, int j)
	{
		stack<int> indexes;
		bool *visited = new bool[V]();
		int currentVertex = j;
		visited[currentVertex] = true;
		indexes.push(currentVertex);
		do{
			currentVertex = indexes.top();
			indexes.pop();
			for(int i=0; i<graphVertices[currentVertex].adjecentIndexes.size(); i++)
			{
				int idx = graphVertices[currentVertex].adjecentIndexes[i];
				
				if(idx == j)
					return true;
				else if(!visited[idx])
					visited[idx] = true;
					indexes.push(idx);
				}
		}while(!indexes.empty());
		return false;
	}
};
#endif //GRAPH_H
