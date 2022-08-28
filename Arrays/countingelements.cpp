//{ Driver Code Starts
// C++ implementation of For each element in 1st
// array count elements less than or equal to it
// in 2nd array
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// function to count for each element in 1st array,
// elements less than or equal to it in 2nd array
class Solution
{
public:
    void print(int arr[],int c){
        
    }
    vector<int> countEleLessThanOrEqual(int arr1[], int arr2[],
                                        int m, int n)
    {
        // int u= sizeof(arr1) / sizeof(arr1[0]);
        // int v= sizeof(arr2) / sizeof(arr2[0]);
        // sort(arr1, arr1 + m);
        sort(arr2, arr2 + n);
         cout<<"Array1 is "<<endl;
        for(int i=0;i<m;i++){
            cout<<arr1[i]<<" ";
        }
        cout<<endl;
        cout<<"Array 2 is "<<endl;
        for(int i=0;i<n;i++){
            cout<<arr2[i]<<" ";
        }
        cout<<endl;

        vector<int> x;
        for (int i = 0; i < m; i++)
        {
            int count = 0;
            int val = arr1[i];
            int j;
            for (j=0; j < n; j++)
            {
                if (arr2[j] <= val)
                {
                    count++;
                }
            }
            x.push_back(count);
        }

        return x;
        // Your code goes here
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        int arr1[m], arr2[n];
        for (int i = 0; i < m; i++)
            cin >> arr1[i];
        for (int j = 0; j < n; j++)
            cin >> arr2[j];
        Solution obj;
        vector<int> res = obj.countEleLessThanOrEqual(arr1, arr2, m, n);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";

        cout << endl;
    }
    return 0;
}
// } Driver Code Ends