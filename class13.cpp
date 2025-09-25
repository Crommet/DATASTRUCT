#include <iostream>
#include <vector>
using namespace std;
// Use adjacency Matrix to represent a graph. 
// Use an example of a graph with at least 7 vertex and 9 edges.
class Graph {
private:
    int numVertices;
    vector<vector<int>> adjMatrix;
public:
    Graph(int n) : numVertices(n), adjMatrix(n, vector<int>(n, 0)) {}
    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }
    void removeEdge(int u, int v) {
        adjMatrix[u][v] = 0;
        adjMatrix[v][u] = 0;
    }
    void display() {
        for (const auto& row : adjMatrix) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << std::endl;
        }
    }

};
int main() {
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    g.addEdge(3, 4);
    g.addEdge(5, 6);
    g.addEdge(4, 5);

    cout << "Adjacency Matrix:" << endl;
    g.display();
    g.removeEdge(1, 4);
    cout << "Adjacency Matrix after removing edge (1, 4):" << endl;
    g.display();

    return 0;
}


