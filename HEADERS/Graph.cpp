#ifndef GRAPH
#define GRAPH

#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph{
private:
	int size; //number of vertices/nodes.
	list<int> *data;
	
	void DFSUtil(int v, bool visited[]){
		//mark current node as visited.
		visited[v] = true;
		cout << v << " ";

		//recursion for adjacent vertices.
		list<int>::iterator it;
		for(it = data[v].begin(); it != data[v].end(); it++)
			if(!visited[*it])
				DFSUtil(*it, visited);
	}
	
	void topologicalSortUtil(int v, bool visited[], stack<int> &Stack){
		visited[v] = true;
		
		list<int>::iterator i;
		for(i = data[v].begin(); i != data[v].end(); i++)
			if(!visited[*i]) topologicalSortUtil(*i, visited, Stack);
		Stack.push(v);
	}
	
public:
	Graph(int s){
		size = s;
		data = new list<int>[size];
	}

	void addEdge(int i, int v){
		data[i].push_back(v);
	}
	
	//breadth first traversal.
	void BFS(int s){
		
		//mark all vertices as not visited. avoid processing same node again.
		bool *visited = new bool[size];
		for(int i = 0; i < size; i++)
			visited[i] = false;

		list<int> q;
		list<int>::iterator it;
		visited[s] = true; //mark current one as visited.
		q.push_back(s);
		
		while(!q.empty()){
			s = q.front();
			cout << s << " ";
			q.pop_front();

			for(it = data[s].begin(); it != data[s].end(); it++){
				if(!visited[*it]){
					visited[*it] = true;
					q.push_back(*it);
				}
			}
		}
	}
	
	//depth first traversal.
	void DFS(int v){
		//mark all vertices as not visited.
		bool* visited = new bool[size];
		for(int i = 0; i < size; i++)
			visited[i] = false;

		DFSUtil(v, visited);
	}
	
	//topological sort.
	void topologicalSort(){
		stack<int> Stack;
		
		bool* visited = new bool[size];
		for(int i = 0; i < size; i++)
			visited[i] = false;
	 
		for(int i = 0; i < size; i++)
			if(visited[i] == false)
				topologicalSortUtil(i, visited, Stack);

		while(Stack.empty() == false) {
			cout << Stack.top() << " ";
			Stack.pop();
		}
	}

};

#endif