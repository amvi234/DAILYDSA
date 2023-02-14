#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    vector<vector<int>>e(4,vector<int>(2));
    e = {{5,4},{6,4},{6,7},{2,3}};
    sort(e.begin(),e.end());
    for(auto x:e){
        //For each element 'y' in 'x'
        for(auto y:x) cout << y << " ";
        cout << endl;
    }
    // return 0;
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