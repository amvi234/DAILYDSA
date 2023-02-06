#include<iostream>
using namespace std;
int func(int n){
    if(n==1){
        return 1;
    }
    if(n==0){
        return 0;
    }
    return func(n-1)+func(n-2);
}
int main(){
    int n;
    cin>>n; 
    cout<< func(n)<<endl;
    return 0;
}