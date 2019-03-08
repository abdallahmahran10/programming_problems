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
				if(!visited[idx]) {
					visited[idx] = true;
					cout<< graphVertices[idx].data << " ";
					indexes.push(idx);
				}
			}
		}while(!indexes.empty());
		
		delete visited;
	}
	//
	void breadthFirstTraversal() 
	{ 
		breadthFirstTraversal(0); 
	}
	//
	void printVertex(int idx)
	{
		cout<<graphVertices[idx].data<<endl;
	}
	//
	void breadthFirstTraversal(size_t s) 
	{
		bool *visited = new bool[V]();
		queue<int> vertices;
		vertices.push(s);
		visited[s] = true;
		while(!vertices.empty())
		{
			int idx = vertices.front();
			vertices.pop();
			printVertex(idx);
			for(int i=0; i<graphVertices[idx].adjecentIndexes.size(); i++)
				if(!visited[graphVertices[idx].adjecentIndexes[i]])
				{
					vertices.push(graphVertices[idx].adjecentIndexes[i]);					
					visited[graphVertices[idx].adjecentIndexes[i]] = true;
				}
		}
		delete visited;
	}
	//
	bool isPathExists(size_t i, size_t j)
	{
		if(i==j)
			return true;
		if(i > V || j > V )
			return false;
		bool *visited = new bool[V]();
		queue<int> vertices;
		vertices.push(i);
		visited[i] = true;
		while(!vertices.empty())
		{
			int idx = vertices.front();
			vertices.pop();
			printVertex(idx);
			for(int adjIdx=0; adjIdx<graphVertices[idx].adjecentIndexes.size(); adjIdx++)
				if(!visited[graphVertices[idx].adjecentIndexes[i]])
				{
					if(graphVertices[idx].adjecentIndexes[adjIdx] == j)
					{
						delete visited;
						return true;
					}
					vertices.push(graphVertices[idx].adjecentIndexes[adjIdx]);					
					visited[graphVertices[idx].adjecentIndexes[adjIdx]] = true;
				}
		}
		delete visited;
		return false;
	}
};
#endif //GRAPH_H
