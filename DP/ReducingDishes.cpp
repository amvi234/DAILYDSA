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
    int solvetab(vector<int>& satisfaction){
         vector<vector<int>>dp(satisfaction.size()+1,vector<int>(satisfaction.size()+1,0));
         for(int index=satisfaction.size()-1;index>=0;index--){
             for(int time=index;time>=0;time--){
                 int i=satisfaction[index]*(time+1)+dp[index+1][time+1];
                 int e=dp[index+1][time];
                 dp[index][time]=max(i,e);
             }
         }
         return dp[0][0];
    }
    int solvetab2(vector<int>& s){
        //  vector<vector<int>>dp(satisfaction.size()+1,vector<int>(satisfaction.size()+1,0));
        vector<int>curr(s.size()+1,0);
        vector<int>next(s.size()+1,0);

         for(int index=s.size()-1;index>=0;index--){
             for(int time=index;time>=0;time--){
                 int i=s[index]*(time+1)+next[time+1];
                 int e=next[time];
                 curr[time]=max(i,e);
             }
             next=curr;
         }
         return next[0];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        // vector<vector<int>>dp(satisfaction.size(),vector<int>(satisfaction.size()+1,-1));
        return solvetab2(satisfaction);
    }
};