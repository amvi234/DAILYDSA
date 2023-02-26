class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int>ans(word.length(),0);
        long long rem=0;
        for(int i=0;i<word.length();i++){
            int curr = (int)(word[i]-'0');
            long long int n = curr+ rem*10;
            // cout<<n<<" ";
            if(n%m==0){
                ans[i]=1;
            }
            rem=n%m;
        }
        return ans;
    }
};