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


void printAllPath(Node* root,vector<int>hold){
    if(root==NULL)return;
    if(root->left==NULL && root->right==NULL){
        for(auto it:hold)cout<<it<<" ";
        cout<<root->val<<endl;
        return;
    }
    hold.push_back(root->val);
    printAllPath(root->left,hold);
    printAllPath(root->right,hold);
}

int main(){
    Node *root=createNode(2);
    root->left=createNode(3);
    root->right=createNode(4);
    root->right->left=createNode(5);
    root->right->right=createNode(6);
    root->left->left=createNode(7);
    root->left->right=createNode(8);
    vector<int>hold;
    printAllPath(root,hold);
   
   
    return 0;
}