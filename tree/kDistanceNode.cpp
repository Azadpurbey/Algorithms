#include<bits/stdc++.h>  //Find all node which is at a distance of K from given target node
#define vll vector<long long>
#define F first
#define S second
using namespace std;
struct Node{
    int val=0;
    Node *left=NULL,*right=NULL;
};
Node* createNode(int x){
    Node *temp=new Node;
    temp->left=NULL;
    temp->right=NULL;
    temp->val=x;
    return temp;
}
void preorder(Node* root,map<Node*,Node*>&parent){
    if(root==NULL)return;
    cout<<root->val<<" ";
    if(root->left!=NULL)parent[root->left]=root;
    if(root->right!=NULL)parent[root->right]=root;
    preorder(root->left,parent);
    preorder(root->right,parent);
}

void KdistanceNode(Node*target,int k,vll &Data,map<Node*,Node*>&parent,map<Node*,int>&vis){
    if(target==NULL)return;
    if(vis.find(target)!=vis.end())return;
    vis[target]==1;
    if(k==0){
        Data.push_back(target->val);
    }
    KdistanceNode(target->left,k-1,Data,parent,vis);
    KdistanceNode(target->right,k-1,Data,parent,vis);
    KdistanceNode(parent[target],k-1,Data,parent,vis);
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
    map<Node*,Node*>parent;
    map<Node*,int>vis;
    vll Data;
    preorder(root,parent);
    parent[root]=root;
    cout<<endl<<"Parents "<<endl;
    for(auto it:parent){
        cout<<it.F->val<<":"<<it.S->val<<endl;
    }    
    cout<<endl<<"ans ";


    KdistanceNode(root->right,2,Data,parent,vis);
    for(auto it:Data)cout<<it<<" ";
    return 0;
}
