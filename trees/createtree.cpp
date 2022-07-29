#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
node *buildTree(node *root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}
void levelordertraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            { // queue still has some child nodes
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void reverselevelordertraversal(node *root)
{
    stack <node *> S;
    queue <node *> Q;
    Q.push(root);

    while (Q.empty() == false)
    {
        /* Dequeue node and make it root */
        root = Q.front();
        Q.pop();
        S.push(root);
  
        /* Enqueue right child */
        if (root->right)
            Q.push(root->right); // NOTE: RIGHT CHILD IS ENQUEUED BEFORE LEFT
  
        /* Enqueue left child */
        if (root->left)
            Q.push(root->left);
    }
   while (S.empty() == false)
    {
        root = S.top();
        cout << root->data << " ";
        S.pop();
    }
}

void inorder(node * root)
{
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right); 
}
void preorder(node * root)
{
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" "; 
    inorder(root->left);
     inorder(root->right);
    
}
void postorder(node * root)
{
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    inorder(root->right); 
     cout<<root->data<<" ";
}
int main()
{
    node *root = NULL;
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout << "printing level order traversal output" << endl;
    
    levelordertraversal(root);
    cout << "printing reverse level order traversal output" << endl;
    reverselevelordertraversal(root);
    cout<<"Inorder"<<endl;
    inorder(root);
    cout<<"preorder"<<endl;
    preorder(root);
    cout<<"postorder"<<endl;
    postorder(root);
    return 0;
}