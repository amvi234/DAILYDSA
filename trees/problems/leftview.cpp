public:
    void solve(Node *root,vector<int>&ans,int level){
        if(root==NULL){
            return;
        }
        if(level==ans.size()){
            ans.push_back(root->data);
        }
        solve(root->left,ans,level+1);
        solve(root->right,ans,level+1);
        
        
    }
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        vector<int>ans;
        int level=0;
        solve(root,ans,level);
        return ans;
       // Your Code here
    }