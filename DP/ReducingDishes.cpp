class Solution {
public:
    int solve(vector<int>& satisfaction,int index,int time, vector<vector<int>>&dp){
        if(index==satisfaction.size()){
            return 0;
        }
        if(dp[index][time]!=-1){
            return dp[index][time];
        }
        int include = satisfaction[index]*(time)+solve(satisfaction,index+1,time+1,dp);
        int exclude = solve(satisfaction,index+1,time,dp);
         dp[index][time]= max(include,exclude);
         return dp[index][time];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>>dp(satisfaction.size(),vector<int>(satisfaction.size()+1,-1));
        return solve(satisfaction,0,1,dp);
    }
};