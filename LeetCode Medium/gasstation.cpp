class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int s=0;
        int current=0;
        int answer=0;
        for(int i=0;i<gas.size();i++){
            int j=i+1;
            int t=gas[i]-cost[i];
            current =current+ t;
            if(current<0){
                current=0;
                answer=j;
            }
            s+=t;cout<<s<<" ";
            }  
return s<0?-1:answer;
        }
    
};