https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
class Solution
{
    public:
    static bool cmp(pair<int,int>a,pair<int,int>b){
        return a.second<b.second;
        }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    
    {
        vector<pair<int,int>>p;
        for(int i=0;i<n;i++){
            pair<int,int>v=make_pair(start[i],end[i]);
            p.push_back(v);
        }
        sort(p.begin(),p.end(),cmp);
        int count=1;
        int endans=p[0].second;
        for(int i=1;i<n;i++){
            if(p[i].first>endans){
                count++;
                endans=p[i].second;
            }
        }
        return count;
        // Your code here
    }
};