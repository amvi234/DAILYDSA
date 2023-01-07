#include<iostream>
#include<queue>
using namespace std;
int main(){
    int arr[]={12, 10, 9, 2, 5, 7, 6};
    priority_queue<int>pq;
    for(int i=0;i<7;i++){
        pq.push(arr[i]);
    }
    for(int i=0;i<6;i++){
       cout<<pq.top()<<" ";
       pq.pop();
    }
}