//
// Created by Arash Khajelou on 3/4/16.
//

#ifndef ALGORITHMCOURSEHW_ARRAYGRAPH_H
#define ALGORITHMCOURSEHW_ARRAYGRAPH_H

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class ArrayGraph {
private:
    int vertexCount;
    bool **adjacencyMatrix;

public:
    ArrayGraph(int _vertexCount) {
        this->vertexCount = _vertexCount;

        this->adjacencyMatrix = new bool *[_vertexCount];
        for (int row = 0; row < _vertexCount; ++row) {
            this->adjacencyMatrix[row] = new bool[_vertexCount];
        }
    }

    friend istream &operator>>(istream &in, ArrayGraph &_arrayGraph) {
        for (int row = 0; row < _arrayGraph.vertexCount; ++row) {
            for (int col = 0; col < _arrayGraph.vertexCount; ++col) {
                in >> _arrayGraph.adjacencyMatrix[row][col];
            }
        }
        return in;
    }

    friend ostream &operator<<(ostream &out, ArrayGraph &_arrayGraph) {
        for (int row = 0; row < _arrayGraph.vertexCount; ++row) {
            for (int col = 0; col < _arrayGraph.vertexCount; ++col) {
                out << _arrayGraph.adjacencyMatrix[row][col] << ' ';
            }
            out << endl;
        }
        return out;
    }

    void bfsTraverse(int baseNode = 0) {
        bool *isVisited = new bool[this->vertexCount];
        bool *isAdded = new bool[this->vertexCount];
        for (int i = 0; i < this->vertexCount; ++i) {
            isVisited[i] = false;
            isAdded[i] = false;
        }

        queue<int> nodesToVisit;
        nodesToVisit.push(baseNode);
        isAdded[baseNode] = true;

        while (!nodesToVisit.empty()) {
            int mustVisit = nodesToVisit.front();
            nodesToVisit.pop();
            cout << mustVisit << endl; //visit the node !
            isVisited[mustVisit] = true;

            for (int col = 0; col < this->vertexCount; ++col) {
                if (this->adjacencyMatrix[mustVisit][col] && !isAdded[col]) {
                    nodesToVisit.push(col);
                    isAdded[col] = true;
                }
            }
        }
    }

    void dfsTraverse(int baseNode = 0) {
        bool *isVisited = new bool[this->vertexCount];
        bool *isAdded = new bool[this->vertexCount];
        for (int i = 0; i < this->vertexCount; ++i) {
            isVisited[i] = false;
            isAdded[i] = false;
        }

        stack<int> nodesToVisit;
        nodesToVisit.push(baseNode);
        isAdded[baseNode] = true;

        while (!nodesToVisit.empty()) {
            int mustVisit = nodesToVisit.top();
            nodesToVisit.pop();
            cout << mustVisit << endl; //visit the node !
            isVisited[mustVisit] = true;

            for (int col = 0; col < this->vertexCount; ++col) {
                if (this->adjacencyMatrix[mustVisit][col] && !isAdded[col]) {
                    nodesToVisit.push(col);
                    isAdded[col] = true;
                }
            }
        }
    }

};

void testBfsAndDfs() {
    int graphVertexCount;
    cin >> graphVertexCount;
    ArrayGraph arrayGraph(graphVertexCount);
    cin >> arrayGraph;
    arrayGraph.bfsTraverse();
    arrayGraph.dfsTraverse();
}


#endif //ALGORITHMCOURSEHW_ARRAYGRAPH_H
