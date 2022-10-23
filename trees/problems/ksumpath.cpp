class Solution{
  public:
  void solve(Node* root, int &c, vector<int>path,int k ){
      if(root==NULL) return;
       path.push_back(root->data);
      solve(root->left,c,path,k);
      solve(root->right,c,path,k);
     
      int sum=0;
      for(int i=path.size()-1;i>=0;i--){
          sum+=path[i];
          if(sum==k){
              c++;
          }
      }
      path.pop_back();
  }
    int sumK(Node *root,int k)
    {
        int c=0;
        vector<int>path;
        solve(root,c,path,k);
        return c;
        // code here 
    }
};