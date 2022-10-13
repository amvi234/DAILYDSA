#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int d[n];
    for(int i=0;i<n;i++){
            cin>>d[i];
    }
    int diff = INT_MAX;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(abs(d[i]-d[j])<diff){
                diff = abs(d[i]-d[j]);
            }
        }
    }
    cout<< diff;
}