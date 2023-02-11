class Solution {
public:
//TABULATION
int solve(vector<int>& days, vector<int>& costs){
        vector<int>dp(days.size()+1,INT_MAX);
        dp[days.size()]=0;
        for(int i=days.size()-1;i>=0;i--){
            int option1=costs[0]+dp[i+1];
            int k;
            for(k=i;k<days.size()&&days[k]<days[i]+7;k++);
            int option2=costs[1]+dp[k];
            for(k=i;k<days.size()&&days[k]<days[i]+30;k++);
            int option3=costs[2]+dp[k];
            dp[i] = min(option1,min(option2,option3));
        }
        return dp[0];
    }
    //RECURSION + MEMOIZATION
    int solve(vector<int>& days, vector<int>& costs,int index,vector<int>&dp){
        if(index>=days.size()){
            return 0;
        }
        if(dp[index]!=INT_MAX){
            return dp[index];
        }
        int option1 = costs[0]+solve(days,costs,index+1,dp);
        int i;
        
        for(i=index; i<days.size() && days[i]<days[index]+7;i++);
        int option2=costs[1]+solve(days,costs,i,dp);
        for(i=index;i<days.size() && days[i]< days[index]+30 ;i++);
        int option3=costs[2]+solve(days,costs,i,dp);
        dp[index] = min(option1,min(option2,option3));
        return dp[index];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size()+1,INT_MAX);
        return solve(days,costs,0,dp);
    }
};