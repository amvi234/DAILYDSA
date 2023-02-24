class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int>m;
        
       
        int ans=INT_MAX;
        int f;int bo=0;
        for(int i=0;i<cards.size();i++){
            if(m.find(cards[i])!=m.end()){
                f=m[cards[i]];
                bo=1;
            }
            m[cards[i]]=i;
            
            if(bo==1)
                ans=min(ans,(i-f+1));
            // cout<<f<<" "<<i<<endl;
        }
        if(bo==0) return -1;
        // for(auto e:m){
        //     cout<<e.first<<" "<<e.second<<endl;
        // }
        return ans;
    }
};