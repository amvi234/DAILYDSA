class Solution {
public:
    int solve(vector<int>& nums,int curr,int prev,vector<vector<int>>&dp){
        if(curr==nums.size()){
            return 0;
        }
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        int take=0;
        if(prev==-1 || nums[curr]>nums[prev]){
            take = 1+solve(nums,curr+1,curr,dp);
        }
        int nottake = 0+solve(nums,curr+1,prev,dp);
        return dp[curr][prev+1]= max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
        return solve(nums,0,-1,dp);
    }
};
 int solveedMOstOptimal(vector<int>& nums){
      if(nums.size()==0){
          return 0;
      }
      
      vector<int>ans;
      ans.push_back(nums[0]);
      for(int i=1;i<nums.size();i++){
          if(nums[i]>ans.back()){
              ans.push_back(nums[i]);
          }
          else{
              int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
              ans[index]=nums[i];
          }
      }
      return ans.size();
    }