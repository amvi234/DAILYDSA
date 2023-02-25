int secondsToRemoveOccurrences(string s) {
    int zeros = 0, seconds = 0;
    for (int i = 0; i < s.size(); ++i) {
        zeros += s[i] == '0';
        if (s[i] == '1' && zeros)
            seconds = max(seconds + 1, zeros);
    }
    return seconds;
}
class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int flag=0;
        for(int i=0;i<s.length()-1;){
           if(s[i]=='0' && s[i+1]=='1')
            {
                flag=1;
                swap(s[i],s[i+1]);
                i++;
                i++;
            }
            else
            {
                i++;
            }
        }

        if(flag==0){
            return 0;
        }
        return 1+secondsToRemoveOccurrences(s);
    }
};