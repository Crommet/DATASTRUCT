//Breadth-First Search (BFS) implementation in C++
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(const vector<vector<int>>& adjList, int start) {
    int n = adjList.size();
    if (start < 0 || start >= n) {
        cout << "Invalid start node." << endl;
        return;
    }
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal starting from node " << start << ": ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
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
    cout << "Enter starting node for BFS: ";
    if (!(cin >> startNode)) {
        cout << "Invalid starting node." << endl;
        return 1;
    }
    bfs(adjList, startNode);
    return 0;
}