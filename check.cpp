#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int s=0;
    int ans=0;
    int a[3]={1,-1,4};
    sort(a,a+3);
       for(int i=1;i<3;i++){
        s=abs(a[i-1]-a[i]);
        ans+=s;
        cout<<s<<endl;
       }
       cout<<ans;
    //    cout<<s;
    // int n,r;
    // cin>>n>>r;

    // long long int val=1;
    // long long int val1=1;
    // long long int val2=1;
    // for(int i=n;i>=1;i--){
    //     val *= i; 
    // }
    // cout<<"val is  "<<val<<endl;
    // for(int i=r;i>=1;i--){
    //     val1 *= i; 
    // }
    // cout<<"val1 is  "<<val1<<endl;
    // int o = n-r;


    // for(int i=o;i>=1;i--){
    //     val2 *= i; 
    // }
    // cout<<"val2 is  "<<val2<<endl;
    // long long x = val/(val2*val1);
    // cout<<x; 
    // ////



    return 0;
}