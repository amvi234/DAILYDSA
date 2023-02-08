class Solution {
public:
//RECURSION + MEMOIZATION - OPTIMIZED WITH MEMOIZATION O(N)
int solveRec(vector<int>& coins, int amount,vector<int>&dp){
    if(amount==0){
        return 0;
    }
    if(amount<0){
        return INT_MAX;
    }
    if(dp[amount]!=-1){
        return dp[amount];
    }
    int mini=INT_MAX;
    for(int i=0;i<coins.size();i++){
        int ans = solveRec(coins,amount-coins[i],dp);
        if(ans!=INT_MAX){
            mini=min(mini,1+ans);
        }
    }
    dp[amount]=mini;

    return mini;
}
//TABULATION 
int solve(vector<int>& coins, int amount){
   vector<int>dp(amount+1,INT_MAX);
    dp[0]=0;
   
    for(int i=1;i<=amount;i++){
        for(int j=0;j<coins.size();j++){
            if(i-coins[j]>=0 && dp[i-coins[j]]!=INT_MAX){
                dp[i]=min(dp[i],1+dp[i-coins[j]]);
            }
        }
    } 

    return dp[amount];

}
    int coinChange(vector<int>& coins, int amount) {
        if(solve(coins,amount)==INT_MAX){
            return -1;
        }
        return solve(coins,amount);
    }
};