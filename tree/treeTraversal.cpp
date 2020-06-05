#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node *left=NULL,*right=NULL;
};
Node* createNode(int x){
    Node *temp=new Node;
    temp->left=NULL;
    temp->right=NULL;
    temp->val=x;
    return temp;
}
void preOrder(Node *root){
    if(root==NULL)return;
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node *root){
    if(root==NULL)return;
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}
void postOrder(Node *root){
    if(root==NULL)return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<" ";
}

int main(){
    Node *root=createNode(2);
    root->left=createNode(3);
    root->right=createNode(4);

    root->left->left=createNode(5);
    root->left->right=createNode(6);

    root->right->left=createNode(7);
    root->right->right=createNode(8);
    root->right->right->left=createNode(9);
    
    cout<<"PreOrder Traversal"<<"  :";
    preOrder(root);
    cout<<endl<<"InOrder Traversal"<<"   :";
    inOrder(root);
    cout<<endl<<"PostOrder Traversal"<<" :";
    postOrder(root);
    return 0;
}