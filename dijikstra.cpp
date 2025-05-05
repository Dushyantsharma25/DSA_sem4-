#include<bits/stdc++.h>
using namespace std;

void print_path(int node,vector<int>& parent){
    if(node == -1){
        return;
    }

    print_path(parent[node],parent);
    cout<<node<<" -> ";
}

void dijik(vector<vector<pair<int,int>>> a,int source){        // node , weight
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> p;  // weight , node
    vector<int> dis(a.size(), INT_MAX);

    vector<int> parent(a.size(),-1);
    dis[source] = 0;
    p.push({0,source});

    while(!p.empty()){
        int node = p.top().second;
        int weight = p.top().first;

        p.pop();

        for(auto i : a[node]){
            int nextnode = i.first;
            int nodeweight = i.second;
            if(weight + nodeweight < dis[nextnode]){
                dis[nextnode] = weight + nodeweight;
                parent[nextnode] = node;
                p.push({dis[nextnode],nextnode});
            }
        }

    }

    for(int i=0;i<a.size();i++){
        cout<<i<<" "<<dis[i]<<"  = ";
        print_path(i,parent);
        cout<<"\n";    
    }

    
    
}

int main(){

    vector<vector<pair<int,int>>> a(5);

    a[0].push_back({1,4});
    a[0].push_back({2,8});
    a[1].push_back({0,4});
    a[1].push_back({4,6});
    a[2].push_back({0,8});
    a[2].push_back({3,2});
    a[3].push_back({2,2});
    a[3].push_back({4,10});
    a[4].push_back({1,6});
    a[4].push_back({3,10});


    dijik(a,0);

    return 0;
}
