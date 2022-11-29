#include<iostream>
using namespace std;
int main(){
    int x;
    cin>>x;
    for(int i=1;i<=x;i++){
        for(int j=1;j<2*x;j++){
            if(j==i || j==2*x-i){
                cout<<i;
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    for(int i=x-1;i>=1;i--){
        for(int j=1;j<=2*x-1;j++){
            if(j==i|| j==2*x-i){
                cout<<i;
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}