// Non-Weighted Graphs using Adjacency List 

// #include <bits/stdc++.h>

#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;



class Graph {
    private:
        unordered_map<string, unordered_set<string> > adjList;

    public: 
        bool addVertex(string vertex) {
            if(adjList.count(vertex) == 0) {
                adjList[vertex];
                return true;
            }
            return false;
        }

        bool addEdge(string vertex1, string vertex2) {
            if(adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0) {
                adjList.at(vertex1).insert(vertex2);
                adjList.at(vertex2).insert(vertex1);
                return true;
            }
            return false;
        }

        bool removeEdge(string vertex1, string vertex2) {
            if(adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0) {
                adjList.at(vertex1).erase(vertex2);
                adjList.at(vertex2).erase(vertex1);
                return true;
            }
            return false;
        }

        bool removeVertex(string vertex){
            if(adjList.count(vertex) != 0){
                for(auto otherVertex: adjList.at(vertex)) {
                    adjList.at(otherVertex).erase(vertex);
                }
                adjList.erase(vertex);
            }
            return false;
        }

        void printGraph() {
            for (auto [vertix, edges] : adjList) {
                cout << vertix << ": [ " ;
                for (auto edge : edges) {
                    cout << edge << " ";
                }
                cout << "]" <<endl;
            }
        }

};

int main() {
    Graph* myGraph = new Graph();

    myGraph-> addVertex("A");
    myGraph-> addVertex("B");
    myGraph-> addVertex("C");
    myGraph->addVertex("D");

    myGraph->addEdge("A","B");
    myGraph->addEdge("A","D");
    myGraph->addEdge("A","C");
    myGraph->addEdge("B","D");
    myGraph->addEdge("C","D");

    myGraph->removeVertex("D");

    myGraph->printGraph();

}