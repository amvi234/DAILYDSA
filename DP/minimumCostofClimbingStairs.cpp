class Solution {
public:
//RECURSION - TLE O(N2)
    int solve1(vector<int>cost,int k){
        if(k==0){
            return cost[0];
        }
        if(k==1){
            return cost[1];
        }
        return min(solve(cost,k-1),solve(cost,k-2))+cost[k];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        
        return min(solve(cost,cost.size()-1),solve(cost,cost.size()-2));
    }
    //RECURSION + MEMOIZATION - OPTIMIZED WITH MEMOIZATION O(N)
    int solve(vector<int>cost,int k,vector<int>&dp){
        if(k==0){
            return cost[0];
        }
        if(k==1){
            return cost[1];
        }
        if(dp[k]!=-1){
            return dp[k];
        }
        dp[k]=min(solve(cost,k-1,dp),solve(cost,k-2,dp))+cost[k];
        return dp[k];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+1,-1);
        return min(solve(cost,cost.size()-1,dp),solve(cost,cost.size()-2,dp));
    }
};
//TABULATION 
int solve3(vector<int>& cost,int k){
        vector<int>dp(k+1);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<k;i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[k-1],dp[k-2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        // vector<int>dp(cost.size()+1,-1);
        return solve3(cost,cost.size());
    }