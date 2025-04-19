#include<iostream>
#include<vector>
using namespace std;

int sum(vector<int> freq,int i,int j){
    int total = 0;
    for(int k = i;k<=j;k++){
        total += freq[k];
    }
    return total;
}

int optimalCost(vector<int> freq,int i,int j){
    if(i>j) return 0;
    if(i == j) return freq[i];
    int s = sum(freq,i,j);
    int mn = INT_MAX;
    for(int k = i;k<=j;k++){
        int cost = optimalCost(freq,i,k-1) + optimalCost(freq,k+1,j);
        if(cost < mn){
            mn = cost;
        } 
    }
    return s + mn;
}

int OBST(vector<int> freq,vector<int> key,int n){
    return optimalCost(freq,0,n-1);
}



int main(){
    vector<int> freq = {38,12,19};
    vector<int> key = {10,20,30};
    int n = 3;
    cout<<OBST(freq,key,n);

    return 0;
}
