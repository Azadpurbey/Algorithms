#include<bits/stdc++.h>
#define F first
#define S second
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
void preorder(Node* root){
    if(root==NULL)return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

Node* lowestAncestor(Node*root,int a,int b){
    if(root==NULL)return NULL;
    if(root->val==a || root->val==b)return root;
    Node* leftAncestor=lowestAncestor(root->left,a,b);
    Node* rightAncestor=lowestAncestor(root->right,a,b);
    if(leftAncestor && rightAncestor)return root;
    if(leftAncestor==NULL)return rightAncestor;
    if(rightAncestor==NULL)return leftAncestor;
}

int main(){
    Node *root=createNode(1);
    root->left=createNode(2);
    root->right=createNode(3);
    root->left->left=createNode(4);
    root->left->right=createNode(5);
    root->right->left=createNode(6);
    root->right->right=createNode(7);
    root->right->right->left=createNode(8);
    preorder(root);
    Node* ans=lowestAncestor(root,6,8);
    cout<<endl<<"common ancestor is "<<ans->val;
    return 0;
}