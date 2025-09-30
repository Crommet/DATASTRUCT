#include <iostream>
#include <vector>
using namespace std;
struct Edge { int src, dest; };
class Graph {
public:
    vector<vector<int>> adjList;
    Graph(vector<Edge> const &edges, int n) {
        adjList.resize(n); // Resize the vector to hold 'n' elements of type 'vector<int>'

        for (auto &edge : edges) {
            adjList[edge.src].push_back(edge.dest);
        }
    }
};
void printGraph(Graph const& graph, int n) {
    for (int i = 0; i < n; i++) {
        cout << i << " --> ";
        for (int v : graph.adjList[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
}
int main() {
    vector<Edge> edges = {
        {0, 1}, {1, 2}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4}
    };
    int n = 6; // Number of nodes in the graph
    Graph graph(edges, n);
    printGraph(graph, n);
    return 0;
}