class Solution {
public:
int ans=0;
    void tr(TreeNode* root,int value){
        if(root==NULL){
            return;
        }
        int t=value*10+root->val;
        if(root->left==NULL && root->right==NULL){
        ans+=t;
        }
        tr(root->left,t);
        tr(root->right,t);
        return;
    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        tr(root,0);
        return ans;
    }
};