class Solution {
public:
int solve(string word1, string word2,int i,int j,vector<vector<int>>&dp){
    if(i==word1.length()){
        return word2.length()-j;
    }
    if(j==word2.length()){
        return word1.length()-i;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=0;
    if(word1[i]==word2[j]){
        return solve(word1,word2,i+1,j+1,dp);
    }
    else{
        int ins=1+solve(word1,word2,i,j+1,dp);
        int del=1+solve(word1,word2,i+1,j,dp);
        int rep=1+solve(word1,word2,i+1,j+1,dp);
        ans=min(ins,min(del,rep));
    }
    return dp[i][j]=ans;
}
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.length()+1,vector<int>(word2.length()+1,-1));
        return solve(word1,word2,0,0,dp);
    }
};
//TABULATION
int st(string a,string b){
    vector<vector<int>>dp(a.length()+1,vector<int>(b.length()+1,0));
    for(int i=0;i<a.length();i++){
        
            dp[i][b.length()]=a.length()-i;
        
    }
    for(int i=0;i<b.length();i++){
        
            dp[a.length()][i]=b.length()-i;
        
    }
    for(int i=a.length()-1;i>=0;i--){
        for(int j=b.length()-1;j>=0;j--){
            int ans=0;
            if(a[i]==b[j]){
                ans= dp[i+1][j+1];
            }
            else{
                int ins=1+dp[i][j+1];
                int del=1+dp[i+1][j];
                int rep=1+dp[i+1][j+1];
                ans=min(ins,min(del,rep));
            }
            dp[i][j]= dp[i][j]=ans;
        }
    }
    return dp[0][0];
}
    int minDistance(string word1, string word2) {
        // vector<vector<int>>dp(word1.length()+1,vector<int>(word2.length()+1,-1));
        // return solve(word1,word2,0,0,dp);
        return st(word1,word2);
    }
};