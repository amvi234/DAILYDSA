#include<unordered_map>
#include<queue>
#include<list>
bool bfs(unordered_map<int,bool>&visited,int node,unordered_map<int,list<int>>&adjList){
    unordered_map<int,int>parent;
     parent[node] = -1;
    visited[node]=1;
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int frontNode=q.front();
        q.pop();
        for(auto n:adjList[frontNode]){
            if(n!=parent[frontNode] && visited[n]==1){
                return true;
            }
            else if(!visited[n]){
                q.push(n);  
                visited[n]=1;
                parent[n]=frontNode;
            }
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
            if(bfs(visited,i,adjList)) return "Yes";
        }
    }
    return "No";
}
