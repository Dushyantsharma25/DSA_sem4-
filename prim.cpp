#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> prim(vector<vector<pair<int,int>>> G){   // g : parent --> (node , weight)
    int size = G.size();
    vector<bool> arr(size, 0);
    vector<pair<int,int>> MST;
    
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> p; // Min heap

    p.push({0, {0, -1}});

    int sum = 0;
    
    while (!p.empty()) {
        int w = p.top().first;
        int node = p.top().second.first;
        int parent = p.top().second.second;
        p.pop();

        if (arr[node]) continue;

        sum += w;
        MST.push_back({node, parent});
        arr[node] = 1;

        for (auto i : G[node]) {
            if (!arr[i.first]) {
                p.push({i.second, {i.first, node}});
            }
        }

        int y = count(arr.begin(), arr.end(), true); 

        if (y == size) {
            cout << "Weight of MST is = " << sum << "\n";
            break;
        } 
    }

    return MST;
}

int main() {
    int n = 5;  
    vector<vector<pair<int, int>>> G(n);
    
    G[0].push_back({1, 2});
    G[1].push_back({0, 2});

    G[0].push_back({2, 1});
    G[2].push_back({0, 1});

    G[1].push_back({2, 1});
    G[2].push_back({1, 1});

    G[2].push_back({3, 2});
    G[3].push_back({2, 2});

    G[2].push_back({4, 2});
    G[4].push_back({2, 2});

    G[3].push_back({4, 1});
    G[4].push_back({3, 1});


    vector<pair<int, int>> MST = prim(G);
    
    cout << "Edges in MST:\n";
    for (auto edge : MST) {
        if (edge.second != -1){
            cout << edge.second << " - " << edge.first << "\n";
        }
    }

    return 0;
}
