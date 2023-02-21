class Node{
        public:
        int data;
        Node* left;
        Node* right;
        Node(int d){
            data=d;
            left=NULL;
            right=NULL;
        }
    };
    class cmp{
        public:
            bool operator()(Node* a,Node* b){
                return a->data>b->data;
            }
    };
class Solution
{
    public:
    void traverse(Node* root,vector<string>&ans,string temp){
        if(root->left==NULL && root->right==NULL){
            ans.push_back(temp);
            return;
        }
        traverse(root->left,ans,temp+'0');
        traverse(root->right,ans,temp+'1');
    }
	public:
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		 priority_queue<Node*,vector<Node*>,cmp>pq;
		 for(int i=0;i<N;i++){
		  Node* temp=new Node(f[i]);
		  pq.push(temp);
		 }
		 while(pq.size()>1){
		     Node* first=pq.top();
		     pq.pop();
		     Node* second=pq.top();
		     pq.pop();
		     Node* sum=new Node(first->data+second->data);
		     sum->left=first;
		     sum->right=second;
		     pq.push(sum);
		 }
		 Node* root=pq.top();
		 vector<string>ans;
		 string temp="";
		 traverse(root,ans,temp);
		 
		 return ans;
		}
        };