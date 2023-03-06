class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        map<int,int>m;
        int n=arr.size();
        int end=arr[n-1];
        for(int i=0;i<arr.size();i++) {
           m[arr[i]]=1;
        }
        int ind=0;
        int ans=0;
        for(int i=1;i<9999;i++){
            if(m[i]==0){
                ind++;
            }
            if(ind==k){
                ans=i;
                break;
            }
        }
        
        return ans;
    }
};