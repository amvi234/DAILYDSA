class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int i=0;
        int j=i+1;
        int k=i+2;
        int c=0;
        while(k<nums.size() && i<nums.size()-2 ){
            if(nums[i]!=nums[j] && nums[j]!=nums[k] && i<j && j<k){
                c++;
                i++;
            }
            else if(nums[i]==nums[j]){
                j++;
                if(k<nums.size()-1 && k-j==1){
                    k++;
                }
            }
            if(nums[i]==nums[k] && k<nums.size()-1){
                k++;
            }
        }
        return c;
    }
};