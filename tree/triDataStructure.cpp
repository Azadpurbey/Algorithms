#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
  char val;
  int cont=0;
  int endsHere=0;
  TreeNode *child[26];
};
TreeNode *getNode(int index){
  TreeNode *temp=new TreeNode();
  temp->val='a'+index;
  temp->cont=0;
  temp->endsHere=0;
  for(int i=0;i<26;i++){
    temp->child[i]=NULL;
  }
  return temp;
}
void insert(TreeNode *root,string word){
  int n=word.length();
  TreeNode *cur=root;
  for(int i=0;i<n;i++){
    int index=word[i]-'a';
    if(cur->child[index]==NULL){
      cur->child[index]=getNode(index);
    }
    cur->child[index]->cont++;
    cur=cur->child[index];
  }
  cur->endsHere++;
}
bool search(TreeNode *root,string word){
  int n=word.length();
  TreeNode *cur=root;
  for(int i=0;i<n;i++){
    if(cur->child[word[i]-'a']!=NULL){
      cur=cur->child[word[i]-'a'];
    }  
    else return false;
  }
  return (cur->endsHere>0);
}
bool startsWith(TreeNode *root,string word){
  int n=word.length();
  TreeNode *cur=root;
  for(int i=0;i<n;i++){
    if(cur->child[word[i]-'a']!=NULL){
      cur=cur->child[word[i]-'a'];
    }  
    else return false;
  }
  return (cur->cont > 0);
}
void traverse(TreeNode *root){
  if(root==NULL)return;
  cout<<root->val;
  for(int i=0;i<26;i++){
    traverse(root->child[i]);
  }
}

int frequency(TreeNode *root,string word){
  int n=word.length();
  TreeNode *cur=root;
  for(int i=0;i<n;i++){
    if(cur->child[word[i]-'a']!=NULL){
      cur=cur->child[word[i]-'a'];
    }  
    else return 0;
  }
  return cur->endsHere;
}
void remove(TreeNode *root,string word){
  int n=word.length();
  TreeNode *cur=root;
  for(int i=0;i<n;i++){
    cur->child[word[i]-'a']->cont--;
    cur=cur->child[word[i]-'a'];
  }
  cur->endsHere--;
}
 

int main(){
  TreeNode *root=getNode('/'-'a');
  insert(root,"azad");
  insert(root,"ashish");
  insert(root,"alok");
  insert(root,"ashok");
  insert(root,"ashish");
  insert(root,"alok");
  insert(root,"alok");
  // traverse(root);
  // cout<<"travers finish"<<endl;
  cout<<frequency(root,"ashish")<<endl;
  remove(root,"alok");
  remove(root,"alok");
  remove(root,"alok");
  remove(root,"alok");
  cout<<frequency(root,"alok")<<endl;
  return 0;
}



