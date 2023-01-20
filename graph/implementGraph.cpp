//https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbFRqQlBNcFZnOTY2SXNPd2FNWnhHa2FUWWZ1d3xBQ3Jtc0tuT1A3aTdGVkZuaURnQmVLUjJPTEI2NXpudTR5WEM2QS14cDMtb0l4YWxhUDJBYVhZcUpMSXBXLTRMSG9TTFpRalZrdmlzZUdtNUIzbnJ6cjFOMHZIX3BxalA5ZWJZd190bW1MdnFIY3k4V0pweHlDWQ&q=https%3A%2F%2Fwww.codingninjas.com%2Fcodestudio%2Fproblems%2Fcreate-a-graph-and-print-it_1214551%3FtopList%3Dlove-babbar-dsa-sheet-problems%26leftPanelTab%3D0%26utm_source%3Dyoutube%26utm_medium%3Daffiliate%26utm_campaign%3DLovebabbar&v=EaK6aslcC5g
#include<iostream>
using namespace std;
#include<unordered_map>
#include<list>
template <typename T>
class graph{
    public:
    unordered_map<T,list<T>>adj;
    void addEdge(T u,T v,bool direction){
        //direction=0 --  undirected graph
        //direction=1 -- directed graph
        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);
        }
    }
    void printAdjList(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};
int main(){
    int n;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;
     int m;
    cout<<"Enter the number of edges"<<endl;
    cin>>m;
    graph<int> g;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0); //creating an undirected graph
     }
     //printing graph
     g.printAdjList();
return 0;
}