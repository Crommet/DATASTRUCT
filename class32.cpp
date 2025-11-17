#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge {
    int src, dest, weight;
};
//Disjoint Set Union (Union-Find) structure
struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }
    bool unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU == rootV)
            return false;
        if (rank[rootU] < rank[rootV])
            parent[rootU] = rootV;
        else if (rank[rootU] > rank[rootV])
            parent[rootV] = rootU;
        else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
        return true;
    }
};
vector<Edge> kruskalMST(int V, vector<Edge>& edges) {
    vector<Edge> result;
    DSU dsu(V);
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });
    for (auto& edge : edges) {
        if (dsu.unite(edge.src, edge.dest)) {
            result.push_back(edge);
            if (result.size() == V - 1)
                break;
        }
    }
    return result;
}
int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    if (!(cin >> V >> E) || V <= 0 || E < 0) {
        cerr << "Invalid input for vertices or edges." << endl;
        return 1;
    }
    vector<Edge> edges(E);
    cout << "Enter edges (source destination weight):" << endl;
    for (int i = 0; i < E; i++) {
        if (!(cin >> edges[i].src >> edges[i].dest >> edges[i].weight) ||
            edges[i].src < 0 || edges[i].src >= V ||
            edges[i].dest < 0 || edges[i].dest >= V) {
            cerr << "Invalid edge input." << endl;
            return 1;
        }
        if(edges[i].src < 0 || edges[i].src >= V ||
           edges[i].dest < 0 || edges[i].dest >= V) {
            cerr << "Edge vertices out of bounds." << endl;
            return 1;
        }
    }
    vector<Edge> mst = kruskalMST(V, edges);
    cout << "Edges in the Minimum Spanning Tree:" << endl;
    int totalWeight = 0;
    for (auto& edge : mst) {
        cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
        totalWeight += edge.weight;
    }
    cout << "Total weight of MST: " << totalWeight << endl;
    return 0;
}