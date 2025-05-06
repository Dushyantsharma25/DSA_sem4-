#include<iostream>
using namespace std;


void dfs(int node , vector<vector<int>> &a,vector<bool> &visited){
    visited[node] = true;

    cout<<node<<" ";


    for(auto it : a[node]){
        if(! visited[it]){
            dfs(it,a,visited);
            visited[it] = true;
        }
    }
}


void bfs(int node, vector<vector<int>> &a){

    vector<bool> visited(a.size(),false);

    queue<int> p;

    p.push(node);

    visited[node] = true;

    while(!p.empty()){
        int y = p.front();

        cout<<y<<" ";

        p.pop();

        for(auto it : a[y]){
            if(!visited[it]){
                p.push(it);
                visited[it] = true;
            }
        }
    }

}


int main(){

    vector<vector<int>> a(5);

    a[0].push_back(1);
    a[0].push_back(2);
    a[1].push_back(0);
    a[1].push_back(3);
    a[1].push_back(4);
    a[2].push_back(0);
    a[3].push_back(1);
    a[4].push_back(1);


    vector<bool> visited(5,false);

    dfs(0,a,visited);cout<<"\n";

    bfs(0,a);

    return 0;
}
