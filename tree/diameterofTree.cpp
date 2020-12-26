#include<iostream>
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
int ans=0;
int height(Node *root){
    if(root==NULL)return 0;
    int l=height(root->left);
    int r=height(root->right); 
    ans=max(ans,l+r+1);
    return max(l,r)+1;
}    
int diameter(Node *root){
    if(root==NULL)return 0;
    int l=height(root->left);
    int r=height(root->right);   
    int ld=diameter(root->left);
    int rd=diameter(root->right); 
    return max(max(ld,rd),l+r+1);
}

int main(){
    Node *root=createNode(2);
    root->left=createNode(3);
    root->right=createNode(4);
    root->right->left=createNode(5);
    root->right->right=createNode(6);
    root->left->left=createNode(7);
    root->left->right=createNode(8);
    //cout<<diameter(root);
    height(root); // another method to find diameter  using ans; 
    cout<<endl<<"another method"<<ans<<endl;
   
    return 0;
}