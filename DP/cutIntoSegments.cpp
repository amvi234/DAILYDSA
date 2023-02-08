#include<bits/stdc++.h>
//RECURSION + MEMOIZATION
int solve(int n,int x,int y,int z,vector<int>&dp){
	if(n==0){
		return 0;
	}
	if(n<0){
		return INT_MIN;
	}
	if(dp[n]!=-1){
		return dp[n];
	}
	int a=solve(n-x,x,y,z,dp)+1;
	int b=solve(n-y,x,y,z,dp)+1;
	int c=solve(n-z,x,y,z,dp)+1;
	dp[n]=max(a,max(b,c));
	return dp[n];
}
//TABULATION
int solvetab(int n,int x,int y,int z){
	vector<int>dp(n+1,INT_MIN);
	dp[0]=0;
	for(int i=1;i<=n;i++){
		if(i-x>=0){
			dp[i]=max(dp[i],dp[i-x]+1);
		}
		if(i-y>=0){
			dp[i]=max(dp[i],dp[i-y]+1);
		}
		if(i-z>=0){
			dp[i]=max(dp[i],dp[i-z]+1);
		}
	}
	if(dp[n]==INT_MIN){
		return 0;
	}
	return dp[n];
}
int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	
	return solvetab(n,x,y,z)<0?0:solvetab(n,x,y,z);
}