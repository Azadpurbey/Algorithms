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

pair<int,int> MaxSum(Node* root){
    pair<int,int>p={0,0};
    if(root==NULL)return p;
    pair<int,int>lp=MaxSum(root->left);
    pair<int,int> rp=MaxSum(root->right);
    
    if(root->left==NULL && root->right==NULL){
        p.first=root->val;
        cout<<root->val<<" "<<p.first<<" "<<p.second<<endl;
    }
    else if(root->left==NULL){
        p.first=root->val+rp.second;
        p.second=max(rp.first,rp.second);
        cout<<root->val<<" "<<p.first<<" "<<p.second<<endl;
    }
    else if(root->right==NULL){
        p.first=root->val+lp.second;
        p.second=max(lp.first,lp.second);
        cout<<root->val<<" "<<p.first<<" "<<p.second<<endl;
    }
    else{
        p.first=root->val+lp.second+rp.second;
        p.second=max(lp.second,lp.first)+max(rp.second,rp.first);
        cout<<root->val<<" "<<p.first<<" "<<p.second<<endl;
    }
    return p;
}

int main(){
    Node *root=createNode(1);
    root->left=createNode(2);
    root->right=createNode(3);
    root->left->left=createNode(4);
    root->right->left=createNode(5);
    root->right->right=createNode(6);
    root->right->left->left=createNode(8);
    pair<int,int>p=MaxSum(root);
    cout<<max(p.F,p.S);
    return 0;
}