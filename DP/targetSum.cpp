class Solution {
public:
int count;
    int solve(vector<int>& nums,int index,int sum, int target,vector<vector<int>>&dp){
        if(index==nums.size()){
            if(sum==target){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{if(dp[index][sum+count]!=INT_MIN) {
            return dp[index][sum+count];
        }
        
        int i = solve(nums,index+1,sum+nums[index],target,dp);
        int e= solve(nums,index+1,sum-nums[index],target,dp);
        dp[index][sum+count]= i+e;
        return dp[index][sum+count];}
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        count = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(nums.size(),vector<int>(2*count+1,INT_MIN));
        return solve(nums,0,0,target,dp);
    }
};