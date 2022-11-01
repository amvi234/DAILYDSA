#include<iostream>
using namespace std;
void selsort(int *arr,int idx,int n){
    if(idx==n){
        return;
    }
    // cout<<"The array element is: "<<arr[3]<<endl;;
    int minIndex=idx;
    for(int i=idx+1;i<n;i++){
        
        if(arr[i]<arr[minIndex]){
           minIndex=i;
        }
       
    }
    swap(arr[minIndex],arr[idx]);
    selsort(arr,idx+1,n);
}

int main(){
    int arr[5]={2,5,1,7,3};
    selsort(arr,0,5);
    cout<<"After sorting: "<<endl;
    for(int i=0;i<5;i++)
        cout<<arr[i]<<" " ;
    return 0;
}