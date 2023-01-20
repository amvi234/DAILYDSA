#include<unordered_map>
#include<queue>
#include<list>
bool dfs(unordered_map<int,bool>&visited,int node,int parent,unordered_map<int,list<int>>&adjList){
    visited[node]=true;
    for(auto n:adjList[node]){
        if(!visited[n]){
            if(dfs(visited,n,node,adjList)) return true;   
        }
        else if(n!=parent){
            return true;
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{ 
    unordered_map<int,list<int>>adjList;
    unordered_map<int,bool>visited;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(dfs(visited,i,-1,adjList)) return "Yes";
        }
    }
    return "No";
}
