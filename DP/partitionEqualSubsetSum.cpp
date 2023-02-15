
class Solution {
public:
    bool solve(int index,vector<int>& nums,int targetsum,vector<vector<int>>&dp){
        if(index>=nums.size()){
            return false;
        }
        if(targetsum<0){
            return false;
        }
        if(targetsum==0){
            return 1;
        }
        if(dp[index][targetsum]!=-1){
            return dp[index][targetsum];
        }
        int incl = solve(index+1,nums,targetsum-nums[index],dp);
        int excl = solve(index+1,nums,targetsum,dp);
        return dp[index][targetsum] = incl | excl;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto i:nums){
            sum+=i;
        }
        vector<vector<int>>dp(nums.size()+1,vector<int>((sum/2)+1,-1));
        if(sum%2!=0) return false;
        else return solve(0,nums,sum/2,dp);
    }
};