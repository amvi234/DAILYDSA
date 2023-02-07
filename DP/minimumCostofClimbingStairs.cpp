class Solution {
public:
    // int solve1(vector<int>cost,int k){
    //     if(k==0){
    //         return cost[0];
    //     }
    //     if(k==1){
    //         return cost[1];
    //     }
    //     return min(solve(cost,k-1),solve(cost,k-2))+cost[k];
    // }
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