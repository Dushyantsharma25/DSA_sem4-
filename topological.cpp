#include<iostream>
using namespace std;

void dfs(int node , vector<bool>&visited , stack<int>&s , vector<vector<int>>&adj)
{
    visited[node] = true;

    for(int i=0;i<adj[node].size();i++)
    {
        if(!visited[adj[node][i]])
        dfs(adj[node][i],visited,s,adj);
    }
    s.push(node);
}

vector<int> topoSort(vector<vector<int>>adj,int v)
{
    vector<bool>visited(v,false);
    stack<int>s;
    dfs(0,visited,s,adj);
    for(int i=0;i<v;i++){
        if(!visited[i])
        dfs(i,visited,s,adj);
    }
    vector<int>ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

int main(){
    int v,e;
    cin>>v>>e;
    vector<vector<int>>adj(v);
    
    for(int i=0;i<e;i++)
    {
        int x,y; cin>>x>>y;
        adj[x].push_back(y); // directed graph
    }

    vector<int>ans = topoSort(adj,v);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    
}
