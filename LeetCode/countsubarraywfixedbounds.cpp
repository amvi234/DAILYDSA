qlink:- https://leetcode.com/problems/count-subarrays-with-fixed-bounds/
T.C:- 0(n)
S.C:-0(n)
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        vector<int>maxa;
        vector<int>mini;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==minK) mini.push_back(i);
            if(nums[i]==maxK) maxa.push_back(i);
        }
        for(int i=0;i<nums.size();i++){
            if(maxK<nums[i] || minK>nums[i]) continue;
            int l=i;
            while(i<nums.size() && nums[i]<=maxK && nums[i]>=minK){
                i++;
            }
            i--;
            int last=l-1;
            for(int j=l;j<=i;j++){
                if(nums[j]==minK){
                    int next=lower_bound(maxa.begin(),maxa.end(),j)-maxa.begin();
                    long long cnt1=j-last;
                    if(next==maxa.size()) continue;
                    long long cnt2=i-maxa[next]+1;
                    if(cnt2>0) ans+=(cnt1*cnt2),last=j;
                }
                else if(nums[j]==maxK){
                    int next=lower_bound(mini.begin(),mini.end(),j)-mini.begin();
                    long long cnt1=j-last;
                    if(next==mini.size()) continue;
                    long long cnt2=i-mini[next]+1;
                    if(cnt2>0) ans+=(cnt1*cnt2),last=j;
                }
            }
        }
        return ans;
    }
};
