#include <iostream>
#include <list>
#include <stack>
using namespace std;
class Graph{
    int numVertices;
    list<int>* adjList;
    void topologicalSortUtil(int v, bool visited[], stack<int>& Stack){
        visited[v] = true;
        for (int neighbor : adjList[v]){
            if (!visited[neighbor]){
                topologicalSortUtil(neighbor, visited, Stack);
            }
        }
        Stack.push(v);
    }
public:
    Graph(int numVertices){
        this->numVertices = numVertices;
        adjList = new list<int>[numVertices];
    }
    void addEdge(int v, int w){
        adjList[v].push_back(w);
    }
    void topologicalSort(){
        stack<int> Stack;
        bool* visited = new bool[numVertices];
        for (int i = 0; i < numVertices; i++)
            visited[i] = false;
        for (int i = 0; i < numVertices; i++){
            if (!visited[i]){
                topologicalSortUtil(i, visited, Stack);
            }
        }
        cout << "Topological Sort Order: ";
        while (!Stack.empty()){
            cout << Stack.top() << " ";
            Stack.pop();
        }
        cout << endl;
        delete[] visited;
    }

};
int main(){
    Graph g(7);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(3, 1);
    g.addEdge(5, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 6);
    g.addEdge(0, 6);
    g.topologicalSort();
    return 0;
}