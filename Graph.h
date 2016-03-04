//
// Created by Arash Khajelou on 3/4/16.
//

#ifndef ALGORITHMCOURSEHW_GRAPH_H
#define ALGORITHMCOURSEHW_GRAPH_H

#include<iostream>
#include <list>
#include <stack>

using namespace std;

// Class to represent a graph
class Graph {
    int verticesCount;    // Number of vertices'

    // Pointer to an array containing adjacency listsList
    list<int> *adj;

    // A function used by topologicalSort
    void topologicalSortUtil(int _vertex, bool _visited[], stack<int> &_stack) {
        // Mark the current node as visited.
        _visited[_vertex] = true;

        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for (i = adj[_vertex].begin(); i != adj[_vertex].end(); ++i)
            if (!_visited[*i])
                topologicalSortUtil(*i, _visited, _stack);

        // Push current vertex to stack which stores result
        _stack.push(_vertex);
    }

public:
    // Constructor
    Graph(int _verticesCount) {
        this->verticesCount = _verticesCount;
        adj = new list<int>[_verticesCount];
    }

    // function to add an edge to graph
    void addEdge(int _vertex1, int _vertex2) {
        adj[_vertex1].push_back(_vertex2); // Add _vertex2 to _vertex1’s list.
    }

    // prints a Topological Sort of the complete graph
    void topologicalSort() {
        stack<int> Stack;

        // Mark all the vertices as not visited
        bool *visited = new bool[this->verticesCount];
        for (int i = 0; i < this->verticesCount; i++)
            visited[i] = false;

        // Call the recursive helper function to store Topological
        // Sort starting from all vertices one by one
        for (int i = 0; i < this->verticesCount; i++)
            if (!visited[i])
                topologicalSortUtil(i, visited, Stack);

        // Print contents of stack
        while (!Stack.empty()) {
            cout << Stack.top() << " ";
            Stack.pop();
        }
    }
};

void testGraphTopologicalSort(){
    // Create a graph given in the above diagram // 7, 5, 11, 3, 10, 8, 9, 2 (largest-numbered available vertex first)
    Graph g(12);
    g.addEdge(5, 11);
    g.addEdge(7, 11);
    g.addEdge(7, 8);
    g.addEdge(3, 8);
    g.addEdge(3, 10);
    g.addEdge(11, 2);
    g.addEdge(11, 9);
    g.addEdge(11, 10);
    g.addEdge(8, 9);

    cout << "Following is a Topological Sort of the given graph \n";
    g.topologicalSort();
}

#endif //ALGORITHMCOURSEHW_GRAPH_H
