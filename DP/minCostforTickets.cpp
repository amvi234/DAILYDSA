class Solution {
public:
//SPACE OPTIMIZATION - S.O:- O(1) constant
// T.C:- O(N)
int solveSpaceOP(int n, vector<int> &days, vector<int> &cost){
    
    int ans = 0;
    
    queue<pair<int, int>> month;
    queue<pair<int, int>> week;
    
    for(int day: days){
        // step-1 remove expired days      
        while(!month.empty() && month.front().first + 30 <= day){
            month.pop();
        }
  
        while(!week.empty() && week.front().first + 7 <= day){
            week.pop();
        }
        
        // step-2 add cost for current day
        week.push(make_pair(day, ans + cost[1]));
        month.push(make_pair(day, ans + cost[2]));
        
        // step - 3 ans update
        ans = min(ans + cost[0], min(week.front().second,month.front().second));
        
    }
    
    return ans;
}
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