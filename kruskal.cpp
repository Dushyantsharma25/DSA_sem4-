#include <iostream>
using namespace std;

// DSU (Disjoint Set Union) for cycle detection
int findParent(int u, vector<int>& parent) {
    if (parent[u] == u) return u;
    return parent[u] = findParent(parent[u], parent); // path compression
}

void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);
    if (u != v) {
        if (rank[u] < rank[v]) {
            parent[u] = v;
        } else if (rank[u] > rank[v]) {
            parent[v] = u;
        } else {
            parent[v] = u;
            rank[u]++;
        }
    }
}

int kruskal(int V, vector<vector<int>>& edges) {
    // Sort edges by weight (ascending)
    sort(edges.begin(), edges.end());

    vector<int> parent(V);
    vector<int> rank(V, 0);

    for (int i = 0; i < V; i++) parent[i] = i;

    int mstWeight = 0;

    for (auto edge : edges) {
        int weight = edge[0];
        int u = edge[1];
        int v = edge[2];

        if (findParent(u, parent) != findParent(v, parent)) {
            mstWeight += weight;
            unionSet(u, v, parent, rank);
            cout << "Edge selected: " << u << " - " << v << " (Weight: " << weight << ")\n";
        }
    }

    return mstWeight;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> edges;

    cout << "Enter edges in the format: u v weight" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v}); // store as {weight, u, v}
    }

    int mstCost = kruskal(V, edges);

    cout << "\nTotal cost of MST: " << mstCost << endl;

    return 0;
}
