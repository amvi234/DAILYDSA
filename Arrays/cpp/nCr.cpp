// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
int nCr(long long n, long long r) {
    // Code here
    long long int val;
    long long int val1;
    long long int val2;
    for(int i=n;i>=1;i--){
        val *= i; 
    }
    for(int i=r;i>=1;i--){
        val1 *= i; 
    }
    int o = n-r;

    for(int i=o;i>=1;i--){
        val2 *= i; 
    }
    long long x = val/(val2*val1);
    return x;
}
};


// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long n, r;
		cin >> n >> r;
		Solution obj;
		int ans = obj.nCr(n, r);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends