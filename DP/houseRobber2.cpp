class Solution {
public:
    int solve(vector<int>&a){
        int n=a.size();
        vector<int>dp(n);
        dp[0]=a[0];
        for(int i=1;i<n;i++){
            int incl=i-2>-1?dp[i-2]:0;
            int excl=dp[i-1];
            dp[i]=max(incl+a[i],excl);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>first(n-1),second(n-1);
        if(n==1){
            return nums[0];
        }
        for(int i=0;i<nums.size();i++){
            if(i!=n-1){
                first.push_back(nums[i]);
            }
            if(i!=0){
                second.push_back(nums[i]);
            }
        }
        return max(solve(first),solve(second));
    }
};