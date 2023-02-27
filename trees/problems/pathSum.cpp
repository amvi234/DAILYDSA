class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
     if(root==NULL) {
         return 0;
     }  
    if(root->left==NULL && root->right==NULL){
        return targetSum==root->val;
    }
    return (hasPathSum(root->left,targetSum-root->val) || hasPathSum(root->right,targetSum-root->val));
     
    }