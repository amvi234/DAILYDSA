class Solution {
public:
int solve(vector<int>& prices,int buy,int index,vector<vector<vector<int>>>&dp,int limit){
        if(index==prices.size()){
            return 0;
        }
        if(limit==0)return 0;
        if(dp[index][buy][limit]!=-1) return dp[index][buy][limit];
        int profit=0;
        if(buy){
            int buyKaro=-prices[index]+solve(prices,0,index+1,dp,limit);
            int skipKaro=0+solve(prices,1,index+1,dp,limit);
            profit=max(buyKaro,skipKaro);
        }
        else{
            int sellkaro=prices[index]+solve(prices,1,index+1,dp,limit-1);
            int skipKaro=0+solve(prices,0,index+1,dp,limit);
            profit=max(sellkaro,skipKaro);
        }
        return dp[index][buy][limit]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(prices,1,0,dp,2);
    }
};