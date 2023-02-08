class Solution {
public:
//RECURSION + MEMOIZATION - OPTIMIZED WITH MEMOIZATION O(N)
    int solve(vector<int>& nums,int n,vector<int>&dp){
        if(n==0){
            return nums[0];
        }
        if(n<0){
            return 0; 
        }
       if(dp[n]!=-1){
        return dp[n];
       }
        int incl=solve(nums,n-2,dp)+nums[n];
        int excl=solve(nums,n-1,dp);
        dp[n]=max(incl,excl);
        return dp[n];
    }
    //TABULATION 
    int solve1(vector<int>&nums,int n){
        vector<int>dp(n);
        dp[0]=nums[0];
        for(int i=1;i<n;++i){
            int incl;
            if((i-2)>-1){
                incl=dp[i-2];
            }
            else{
                incl=0;
            }
            int excl=dp[i-1];
            dp[i]=max(incl+nums[i],excl);
        }
        return dp[n-1];
    }
    //SPACE OPTIMIZATATION
    int solve1(vector<int>&nums,int n){
        int prev2=0;
        int prev=nums[0];
        for(int i=1;i<n;++i){
            int ans=i-2>-1?prev2:0;
            ans=max(nums[i]+prev2,prev);
            prev2=prev;
            prev=ans;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
       
        return solve1(nums,nums.size());
    }
};