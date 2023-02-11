class Solution {
public: 
vector<vector<int>>ans;
    void solve(int index,vector<int>& candidates, int target,vector<int>&temp){
        if(target==0){
            ans.push_back(temp);
            return ; 
        }
        if(target<0){
            return;
        }
        if(index==candidates.size()){
            return;
        }
        solve(index+1,candidates,target,temp);
        temp.push_back(candidates[index]);
        solve(index,candidates,target-candidates[index],temp);
        temp.pop_back();
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        solve(0,candidates,target,temp);
        return ans;
    }
};