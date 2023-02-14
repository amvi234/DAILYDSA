class Solution {
public:
    static bool check(vector<int>&a,vector<int>&b){
        if(a[0]>=b[0] && a[1]>=b[1] && a[2]>=b[2]){
            return true;
        }
        return false;
    }
    int solve(int n, vector<vector<int>>& a){
       
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);
        
        for(int curr = n-1; curr>=0; curr--){
            for(int prev = curr-1; prev>=-1; prev--){
                
                // include
                int take = 0;
                if(prev == -1 || check(a[curr], a[prev]))
                    take = a[curr][2] + nextRow[curr+1];
                    
                // exclude
                int notTake = 0 + nextRow[prev+1];
                
                currRow[prev+1] = max(take, notTake);
            }
            
            nextRow = currRow;
        }
        
        return nextRow[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &e:cuboids){
            sort(e.begin(),e.end());
        }
        sort(cuboids.begin(),cuboids.end());
        int n=cuboids.size();
        return solve(n,cuboids);
    }
};