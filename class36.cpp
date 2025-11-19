//IDS (Iterative Deepening Search) Algorithm in C++
#include <iostream>
#include <list>
using namespace std;

class Graph{
    int numVertices;
    list<int>* adjList;
    bool DLS(int v, int target, int limit);
public:
    Graph(int numVertices);
    void addEdge(int v, int w);
    bool IDDFS(int v, int target, int maxDepth);
};
Graph::Graph(int numVertices){
    this->numVertices = numVertices;
    adjList = new list<int>[numVertices];
}
void Graph::addEdge(int v, int w){
    adjList[v].push_back(w);
}
// A function to perform Depth-Limited Search from given source 'src'
bool Graph::DLS(int src, int target, int limit){
    if (src == target) return true;
    if (limit <= 0) return false;
    for (auto i = adjList[src].begin(); i != adjList[src].end(); ++i){
        if (DLS(*i, target, limit - 1)) return true;
    }
    return false;
}
// IDDFS to search for target node
bool Graph::IDDFS(int src, int target, int maxDepth){
    for (int depth = 0; depth <= maxDepth; depth++){
        if (DLS(src, target, depth)) return true;
    }
    return false;
}
int main(){
    // Create a graph with 7 nodes
    Graph g(9);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    g.addEdge(3, 7);
    g.addEdge(4, 8);
    int target = 8, maxDepth = 3, src = 0;
    if (g.IDDFS(src, target, maxDepth))
        cout << "Target " << target << " found within depth " << maxDepth << endl;
    else
        cout << "Target " << target << " not found within depth " << maxDepth << endl;
    return 0;
}