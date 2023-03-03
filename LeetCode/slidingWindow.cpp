class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()>haystack.size()) return -1;
        int i=0;
        int j=0;
        for(;i<haystack.size();i++){  
            if(j==needle.size()){
                return i-needle.size();;
            }         
            if(needle[j]==haystack[i] && j < needle.size()){
                j++;
            }
            else{
                i=i-j;
                j=0;  
            }
        }
        if(j==needle.size()){
            return i-needle.size();
        }
        return -1;
    }
};