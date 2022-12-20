#include <bits/stdc++.h> 
void heapify(vector<int> &arr,int n,int &i){
    int s=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && arr[s]>arr[l]){
        s=l;
    }
    if(r<n && arr[s]>arr[r]){
        s=r;
    }
    if(s!=i){
        swap(arr[s],arr[i]);
        heapify(arr,n,s);
    }
}
vector<int> buildMinHeap(vector<int> &arr)
{
    int n=arr.size();
    for(int i=n-1;i>=0;i--){
        heapify(arr,n,i);
    }
    return arr;
    // Write your code here
}
