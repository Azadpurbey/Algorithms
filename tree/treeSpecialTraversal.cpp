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
void levelOrder(Node* root){
    queue<Node*>qu;
    qu.push(root);
    while(!qu.empty()){
        Node* cur=qu.front();
        if(cur!=NULL){
            cout<<cur->val<<" ";
            if(cur->left!=NULL)qu.push(cur->left);
            if(cur->right!=NULL)qu.push(cur->right);
        }  
        qu.pop();
    }
}
void verticalOrderHelper(Node* root,int level,map<int,vector<int>>&mp){ //used in verticalOrder traversal
  if(root==NULL)return;
  mp[level].push_back(root->val);
  verticalOrderHelper(root->left,level-1,mp);
  verticalOrderHelper(root->right,level+1,mp);
}
void verticalOrder(Node* root){
  map<int,vector<int>>mp;
  verticalOrderHelper(root,0,mp);
  for(auto it:mp){
    for(auto it1:it.second){
      cout<<it1<<" ";
    }
  }
}
void zigZaghelper(Node* root,stack<Node*>&st,int &flag){
  stack<Node*>holder;
  Node *cur;
  while(!st.empty()){
    cur=st.top();st.pop();
    if(flag==0){
      if(cur->left!=NULL){
        holder.push(cur->left);
        cout<<cur->left->val<<" ";
      }
      if(cur->right!=NULL){
        holder.push(cur->right);
        cout<<cur->right->val<<" ";
      }
    }
    else{
      if(cur->right!=NULL){
        holder.push(cur->right);
        cout<<cur->right->val<<" ";
      }
      if(cur->left!=NULL){
        holder.push(cur->left);
        cout<<cur->left->val<<" ";
      }
    }
  }
  swap(st,holder);
}

void zigZagtraversal(Node* root){
  stack<Node*>st;
  if(root==NULL)return;
  cout<<root->val<<" ";
  st.push(root);
  int flag=0;
  while(!st.empty()){
    zigZaghelper(root,st,flag);
    flag=!flag;
  }
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
    cout<<endl<<"levelOrder Traversal"<<"   :";
    levelOrder(root);
    cout<<endl<<"verticalOrder Traversal"<<":";
    verticalOrder(root);
    cout<<endl<<"zigZagOrder Traversal"<<"  :";
    zigZagtraversal(root);
    return 0;
}