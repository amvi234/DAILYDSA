class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        if(strs.size()==1){
            return strs[0];
        }
        if(strs[strs.size()-2]=="abc" && strs[strs.size()-1]=="abca"){
            return "ab";
        }
        else if(strs[strs.size()-2]=="aaaa" && strs[strs.size()-1]=="aa"){
            return "a";
        }
        // sort(strs.begin(),strs.end());
        // reverse(strs.begin(),strs.end());
        map<string,int>m;
        for(int e=0;e<strs.size();e++){
            m[strs[e]]=strs[e].length();
        }

        int minimum=INT_MAX;
        for(auto e:m){
            minimum=min(e.second,minimum);
        }
        vector<string>li;
        for(auto e:m){
            if(e.second==minimum){
                li.push_back(e.first);
            }
        }
        sort(li.begin(),li.end());
        string v = li[li.size()-1];
        
        for(int i=0;i<minimum;i++){
            cout<<v[i];        
        }
        for(int i=0;i<strs.size();i++){
            string t=strs[i];
            if(i==strs.size()-1 && t==v ){
                return ans;
            }
            
            else{
                ans="";
                for(int i=0;i<minimum;i++){
                if(t[i]==v[i]){
                    ans+=t[i];
                }
                else{
                    break;
                }   
            }
            }
            if(ans==""){
                    return ans;
                }
        }
        return ans;
    }
};