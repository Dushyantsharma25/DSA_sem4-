#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;


class Graph {
public:
    int vertices; 
    vector<vector<int>> adjList;
    Graph(int V) {
        vertices = V;
        adjList.resize(V);
    }


    void addEdge(int u, int v) {
        adjList[u-1].push_back(v-1);  
        adjList[v-1].push_back(u-1); 
    }

    
    void DFS(int start) {
        vector<bool> visited(vertices, false);
        cout << "DFS starting from vertex " << start << ": ";
        DFSHelper(start-1, visited); 
        cout << endl;
    }

    void DFSHelper(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex + 1 << " ";  

        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                DFSHelper(neighbor, visited);
            }
        }
    }
 
    void BFS(int start) {
        vector<bool> visited(vertices, false);
        queue<int> q;
        visited[start-1] = true;  
        q.push(start-1);   
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current + 1 << " "; 
            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        int d=0;
        while(vertices>d){
            if(visited[d] == 1){
                BFS(d);
            }
            d++;
        }
        cout << endl;
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    Graph g(V);
    cout << "Enter the number of edges: ";
    cin >> E;
    cout << "Enter the edges (u v) one by one:\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    int start;
    cout << "Enter the starting vertex for DFS and BFS: ";
    cin >> start;
    g.DFS(start);
    cout << "BFS starting from vertex " << start << ": ";
    g.BFS(start);
    return 0;
}
