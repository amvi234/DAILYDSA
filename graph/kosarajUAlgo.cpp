#include<bits/stdc++.h>
void toposort(int node, unordered_map<int, list<int> > &adj, vector<int> &vis, stack<int> &st){
    vis[node] = true;
    for(int i: adj[node]){
        if(!vis[i])toposort(i, adj, vis, st);
    }
    st.push(node);
}

void dfs(int node,vector<int> &vis,unordered_map<int,list<int>> &adj){
    vis[node] = true;
    for(int i:adj[node])
        if(!vis[i]) dfs(i,vis,adj);
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	unordered_map<int, list<int> > adj;
    unordered_map<int,list<int> > adj1;
    for(int i=0; i<edges.size(); i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj1[edges[i][1]].push_back(edges[i][0]);
    }
    
    stack<int> st;
    vector<int> vis(v,false);
    //first step(make topological sort)
    for(int i=0; i<v; i++)
        if(!vis[i])toposort(i,adj,vis,st);
    
    //second step (transpose graph i.e change arrow dir of a graph)
    //we have already done this step by making adj1 above
    
    
    //step third, apply dfs on adj1 using topo order and count
    int count =0;
    fill(vis.begin(), vis.end(), false);
    
    while(!st.empty()){
        int node = st.top();
        st.pop();
        
        if(!vis[node]){
            count++;
            dfs(node, vis, adj1);
        }
    }
    return count;
}