// DFS (Depth-First Search) implementation in C++
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void DFS(int start, vector<vector<int>>& adjList){
    vector<bool> visited(adjList.size(), false);
    stack<int> s;
    s.push(start);
    while (!s.empty()) {
        int node = s.top();
        s.pop();
        if (!visited[node]) {
            visited[node] = true;
            cout << node << " ";
            for (auto it = adjList[node].rbegin(); it != adjList[node].rend(); ++it) {
                if (!visited[*it]) {
                    s.push(*it);
                }
            }
        }
    }
}
int main() {
    int vertices, edges;
    cout << "Enter number of vertices and edges: ";
    if (!(cin >> vertices) || vertices <= 0) {
        cout << "Invalid number of vertices." << endl;
        return 1;
    }
    cout << "Enter number of edges: ";
    if (!(cin >> edges) || edges < 0) {
        cout << "Invalid number of edges." << endl;
        return 1;
    }
    vector<vector<int>> adjList(vertices);
    cout << "Enter edges (u v) for an undirected graph:" << endl;
    for (int i = 0; i < edges; ++i) {
        int u, v;
        if (!(cin >> u >> v) || u < 0 || u >= vertices || v < 0 || v >= vertices) {
            cout << "Invalid edge input." << endl;
            return 1;
        }
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
    }
    int startNode;
    cout << "Enter starting node for DFS: ";
    if (!(cin >> startNode)) {
        cout << "Invalid starting node." << endl;
        return 1;
    }
    DFS(startNode, adjList);
    return 0;
}