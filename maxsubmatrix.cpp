// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    public:
    int Sum(vector<vector<int>> mat,int i, int j, int k)
   {
       int sum = 0;
       for(int p=i;p<i+k;p++)
       {
           for(int q=j;q<j+k;q++)
           {
               sum+=mat[p][q];
           }
       }
       return sum;
   }
    int Maximum_Sum(vector<vector<int>> &mat,int N,int K){
        // Your code goes here
          int max=0;
       for(int i=0;i<=N-K;i++)
       {
           for(int j=0;j<=N-K;j++)
           {
               int s=Sum(mat,i,j,K);
               if(s>max)
               {
                   max=s;
               }
           }
       }
       return max;
   
       
    }  
};


// { Driver Code Starts.

int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
    	int N;
        cin>>N;
        vector<vector<int>> mat(N,vector<int>(N,0));
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>mat[i][j];
            }
        }
        
        int k;cin>>k;
        Solution obj;
        cout << obj.Maximum_Sum(mat,N,k)<<"\n";
    }
        
    return 0;
}
  // } Driver Code Ends