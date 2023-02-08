#include <bits/stdc++.h>
//TABULATION 
long long int st(int n){
    vector<long long int>dp(n+1,0);
    dp[1]=0;
    dp[2]=1;
    for(int i=3;i<=n;i++){
        long long int f=dp[i-1]%1000000007;
        long long int s=dp[i-2]%1000000007;
        long long int sum=(f+s)%1000000007;
        long long int ans=((i-1)*sum)%1000000007;
        dp[i]=ans;
    }
    return dp[n];
}
//RECCURSION + MEMOIZATION
long long int solve(int n, vector<long long int>&dp){
    if(n==1) return 0;
    if(n==2) return 1;
    if(dp[n]!=-1) return dp[n];
    dp[n]=((n-1)%1000000007)*((solve(n-2,dp)%1000000007)+solve(n-1,dp)%1000000007)%1000000007;
    return dp[n];
}
long long int countDerangements(int n) {
   
    return st(n);
}