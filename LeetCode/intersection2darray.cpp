https://leetcode.com/problems/intersection-of-multiple-arrays/
class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                m[nums[i][j]]++;
        }
        }
        
        vector<int>ans;
        for(auto a:m){
            if(a.second==nums.size()){
                ans.push_back(a.first);
            }
        }
        return ans;
    }
};