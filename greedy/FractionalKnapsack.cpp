//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    static bool cmp( pair<double,Item>a, pair<double,Item>b){
        return a.first>b.first;
        }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double,Item>>p;
        for(int i=0;i<n;i++){
            pair<double,Item>m = make_pair((1.0*arr[i].value)/(arr[i].weight),arr[i]);
            p.push_back(m);
        }
        sort(p.begin(),p.end(),cmp);
        double totalScore=0;
        for(int i=0;i<n;i++){
            if(p[i].second.weight>W){
                totalScore+=W*p[i].first;
                W=0;
            }
            else{
                totalScore+=p[i].second.value;
                W=W-p[i].second.weight;
            }
        }
        return totalScore;
        // Your code here
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends