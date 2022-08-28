//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    int flag=0;
	    
	    vector<int>p;
	    vector<int>s;
	    for(int i=0;i<n;i++){
	        if(arr[i]<0){
	            s.push_back(arr[i]);
	        }
	        else if(arr[i]>=0){
	            p.push_back(arr[i]);
	        }
	    }
	    int c=0;
	    int d=1;
	    if(arr[0]<0 && p.size()>0){
	        arr[0]=p[0];
	       
	    }
	    else if(arr[0]<0 && p.size()==0){
	        arr[0]=s[0];
	        c=1;
	    }
	    
	    for(int i=1;i<n;i++){
	        
	        if(i%2==1  && c<s.size() && s.size()>0){
	            arr[i]=s[c];
	            c++;
	        }
	        else if(i%2==0  && d<p.size() && p.size()>0){
	            arr[i]=p[d];
	            d++;
	        }
	        else if(p.size()>s.size()){
	            arr[i]=p[d];
	            d++;
	        }
	        else if(s.size()>p.size()){
	            arr[i]=s[c];
	            c++;
	        }
	    }
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends