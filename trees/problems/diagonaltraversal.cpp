void pre(Node *root,map<int,vector<int>>&m,int level)
{
    if(root==NULL){
        return;
    }
    m[level].push_back(root->data);
    pre(root->left,m,level+1);
    pre(root->right,m,level);
}
vector<int> diagonal(Node *root)
{
   // your code here
   map<int,vector<int>>m;
   pre(root,m,0);
   vector<int>ans;
   for(auto i:m){
       for(auto j:i.second){
           ans.push_back(j);
       }
   }
   return ans;
}