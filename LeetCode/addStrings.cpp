#include<math.h>
class Solution {
public:
    string addStrings(string num1, string num2) {
        int a=num1.length()-1;
        int b=num2.length()-1;
        string ans="";
        int carry=0;
        int index=0;
        while(a>=0 || b>=0 || carry){
            long  sum=0;
            if(a>=0){
                sum+=(num1[a]-'0');
                a--;
            }
            if(b>=0){
                sum+=(num2[b]-'0');
                b--;
            }
            sum+=carry;
            carry = sum /10;
            
            sum=sum%10;
            
            ans.push_back(char(sum+'0'));
           
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};