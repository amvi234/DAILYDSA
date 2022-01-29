// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        vector<string>temp;
        string s="";
        for(int i=0;i<S.length();i++){
            if(S[i] == '.'){
                temp.push_back(s);
                s="";
            }
            else{
                s+=S[i];
            }
            }
            temp.push_back(s);
            string ans="";
            for(int i=temp.size()-1;i>0;i--){
                ans+=temp[i];
                ans+=".";
            }
            ans+=temp[0];
            return ans;
        // code here 
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends