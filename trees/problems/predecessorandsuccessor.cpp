#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    BinaryTreeNode<int>* temp = root;
    int pr=-1;
    int su=-1;
    while(temp->data!=key){
        if(temp->data>key){
            su = temp->data;
            temp = temp->left;
        }
        else{pr=temp->data;
        temp=temp->right;}
    }
    BinaryTreeNode<int>* leftt = temp->left;
    while(leftt!=NULL){
        pr = leftt->data;
        leftt = leftt->right;
    }
    BinaryTreeNode<int>* rightt = temp->right;
    while(rightt!=NULL){
        su = rightt->data;
        rightt = rightt->left;
    }
    return {pr,su};
    // Write your code here.
}
