#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int findMinKeyVertex(const vector<int>& key, const vector<bool>& mstSet, int V) {
    int minKey = INT_MAX;
    int minIndex = -1;

    for (int v = 0; v < V; ++v) {
        if (!mstSet[v] && key[v] < minKey) {
            minKey = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void printMST(const vector<int>& parent, const vector<vector<int>>& graph, int V) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; ++i) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
    }
}

void primMST(const vector<vector<int>>& graph, int startNode) {
    int V = graph.size();

    // Vector to store the parent of each vertex in MST
    vector<int> parent(V, -1);
    // Vector to store the key values of vertices
    vector<int> key(V, INT_MAX);
    // Vector to track if a vertex is included in MST
    vector<bool> mstSet(V, false);

    // Set the key of the start node to 0
    key[startNode] = 0;
    // Start with the start node
    parent[startNode] = -1;

    for (int count = 0; count < V - 1; ++count) {
        int u = findMinKeyVertex(key, mstSet, V);

        mstSet[u] = true;

        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, V);
}

int main() {
    int V=6;

    // Create a 2D vector for the adjacency matrix
    vector<vector<int>> graph(V, vector<int>(V));

    graph = {{0, 3, 0, 0, 0, 1},
             {3, 0, 2, 1, 10, 0},
             {0, 2, 0, 3, 0, 5},
             {0, 1, 3, 0, 5, 0},
             {0, 10, 0, 5, 0, 4},
             {1, 0, 5, 0, 4, 0}
            };

    int startNode=0;

    primMST(graph, startNode);

    return 0;
}
