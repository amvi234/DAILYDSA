//T.C:- O(N)
//S.C:- O(N)
#include<bits/stdc++.h>
using namespace std;
// int fib(int n,vector<int>&a){
//     //RECURSION AND MEMOIZATION
//         if(n<=1){
//            return n;
//         }
//         if(a[n]!=-1){
//                 return a[n];
//         }
//         a[n]=fib(n-1,a)+fib(n-2,a);
//         return a[n];
// }
int main()
{
        int n;
        cin>>n;
        
        // vector<int>a(n+1);
        //TABULATION
        // a[0]=0;
        // a[1]=1;
        // for(int i=2;i<=n;i++){
        //         a[i]=a[i-1]+a[i-2];
        // }
        // cout<< a[n];
        // return 0;
        //  for(int i=0;i<=n;i++){
        //         a[i]=-1;
        // }
        // cout<<fib(n,a) ;
        //SPACE OPTIMISATION
        int curr,prev=0,prev2=1;
        for(int i=2;i<=n;i++){
            curr=prev+prev2;
            prev=prev2;
            prev2=curr;
        }
        cout<<curr;
        return 0;
}