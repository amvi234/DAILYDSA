class Solution
{
public:
     void solve(Node* root,int sum,int &maxlen,int len,int &maxsum){
            if(root==NULL){
                if(len>maxlen){
                    maxlen=len;
                    maxsum=sum;
                }
                else if(len==maxlen){
                    maxsum=max(sum,maxsum);
                }
                return;
            }
            sum=sum+root->data;
            solve(root->left,sum,maxlen,len+1,maxsum);
            solve(root->right,sum,maxlen,len+1,maxsum);
        }
    
    int sumOfLongRootToLeafPath(Node* root)
    {
        //code here
        int len=0;
        int maxlen=0;
        int sum=0;
        int maxsum=INT_MIN;
        solve(root,sum,maxlen,len,maxsum);
        return maxsum;
    }
};