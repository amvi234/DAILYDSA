class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i=0;
        if(blocks.length()<k){
            return 0;
        }
        int t=0;
        if(blocks.length()==k){
            for(int p=0;p<blocks.length();p++){
                if(blocks[p]=='W') t++;
            }
            return t;
        }
        int ans=INT_MAX;
        while(i<=blocks.length()-k){
            int count=0;
            for(int j=i;j<k+i;j++){
                if(blocks[j]=='W'){
                    count++;
                }
            }
            i=i+1;
            ans=min(ans,count);
        }
        return ans;
    }
};