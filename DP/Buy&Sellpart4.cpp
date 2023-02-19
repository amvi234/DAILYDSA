class Solution {
public:
int solve(vector<int>& prices,int buy,int index,int op,vector<vector<int>>&dp,int k){
        if(index==prices.size()){
            return 0;
        }
        if(op==2*k) return 0;
        if(dp[index][op]!=-1) return dp[index][op];
        int profit=0;
        if(op%2==0){
            int buyKaro=-prices[index]+solve(prices,0,index+1,op+1,dp,k);
            int skipKaro=0+solve(prices,1,index+1,op,dp,k);
            profit=max(buyKaro,skipKaro);
        }
        else{
            int sellkaro=prices[index]+solve(prices,1,index+1,op+1,dp,k);
            int skipKaro=0+solve(prices,0,index+1,op,dp,k);
            profit=max(sellkaro,skipKaro);
        }
        return dp[index][op]=profit;
}
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(prices.size()+1,-1));
        return solve(prices,1,0,0,dp,k);
    }
};