#include <bits/stdc++.h> 
#include<stack>
#include<list>
#include<unordered_map>
void topo( vector<bool>&visited,int node,unordered_map<int,list<int>>&adj,stack<int>&s){
    visited[node]=1;
    for(auto n:adj[node]){
        if(!visited[n]){
            topo(visited,n,adj,s);
        }
    }
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int,list<int>>adj;
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
    stack<int>s;
    vector<bool>visited(v);
    for(int i=0;i<v;i++){
        if(!visited[i]){
               topo(visited,i,adj,s);
        }
    }
    vector<int>ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}