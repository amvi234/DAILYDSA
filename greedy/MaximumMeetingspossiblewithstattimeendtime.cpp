//https://practice.geeksforgeeks.org/problems/maximum-meetings-in-one-room/1
class Solution{
public:
// static bool cmp(pair<int,int>a,pair<int,int>b){
//         return a.second<b.second;
//         }
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        pair<int,int>p[N];
        for(int i=0;i<N;i++){
            p[i].first=F[i];
            p[i].second=i+1;
        }
        
        sort(p,p+N);
        vector<int>ans;
        int endans=p[0].first;
        ans.push_back(p[0].second);
        for(int i=1;i<N;i++){
            if(endans<S[p[i].second-1]){
                ans.push_back(p[i].second);
                endans=p[i].first;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};