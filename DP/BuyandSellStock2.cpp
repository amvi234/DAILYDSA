class Solution {
public:
    int solve(vector<int>& prices,int buy,int index,vector<vector<int>>&dp){
        if(index==prices.size()){
            return 0;
        }
        if(dp[index][buy]!=-1) return dp[index][buy];
        int profit=0;
        if(buy){
            int buyKaro=-prices[index]+solve(prices,0,index+1,dp);
            int skipKaro=0+solve(prices,1,index+1,dp);
            profit=max(buyKaro,skipKaro);
        }
        else{
            int sellkaro=prices[index]+solve(prices,1,index+1,dp);
            int skipKaro=0+solve(prices,0,index+1,dp);
            profit=max(sellkaro,skipKaro);
        }
        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        return solve(prices,1,0,dp);
    }
};