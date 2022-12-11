class info{
    public:
        int maxi;
        int mini;
    bool isBST;
        int size;
    
};
info solve(TreeNode<int>* root, int &ms){
    if(!root){
        return {INT_MIN,INT_MAX,true,0};
    }
    info left=solve(root->left,ms);
    info right=solve(root->right,ms);
    
    info currNode;
    currNode.size=left.size+right.size+1;
    currNode.maxi = max(root->data,right.maxi);
    currNode.mini = min(root->data,left.mini);
    
    if(left.isBST && right.isBST && (root->data>left.maxi && root->data<right.mini)){
        currNode.isBST = true;
    }
    else{
        currNode.isBST=false;
    }
    if(currNode.isBST){
        ms=max(ms,currNode.size);
    }
    return currNode;
}
int largestBST(TreeNode<int>* root) 
{
    int ms = 0;
    info t=solve(root,ms);
    return ms;
}
