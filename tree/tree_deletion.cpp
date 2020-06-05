#include<bits/stdc++.h>
using namespace std;

struct binaryTree{
  int info;
  binaryTree *left;
  binaryTree *right;
};

binaryTree *createNode(int data){
  binaryTree *root=new binaryTree();
  root->info=data;
  root->left=root->right=NULL;
 return root;
}
void preOrderTraverse(binaryTree *root){
  if(root){
    cout<<root->info<<" ";
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
  }
}

 binaryTree * search(binaryTree * root,int key){
   if(root==NULL) return NULL;
   else if(key<root->info) return search(root->left, key);
   else if(key>root->info) return search(root->right, key);
   return root;
 }

 binaryTree *findMax(binaryTree *root){
   binaryTree *max=root;
   while(max->right){
   max=max->right;
   }

 return max;
 }

 binaryTree *Delete(binaryTree *root,int key){
   binaryTree *temp;
   if(root==NULL){
   	   	cout<<"no such element exist";
   	   	cout<<"a1"<<endl;
   }

   else if(key<root->info){
   	    cout<<"a2"<<endl;
   	   	root->left=Delete(root->left,key);
   }

   else if(key>root->info){
   	cout<<"a3"<<endl;
   	  root->right=Delete(root->right,key);
   }
   //cout<<"test"<<endl;
   else{
       cout<<"AZADA"<<endl;
      if(root->left!=NULL && root->right!=NULL){
         cout<<"AZAD1"<<endl;
         temp=findMax(root->left);
      	root->info=temp->info;
      	root->left=Delete(root->left,temp->info);
      }
       cout<<"test"<<endl;
     if(root->right==NULL) cout<<"aza";
     cout<<"aza1";
     if(root->left==NULL || root->right==NULL){
      	temp=root;
      cout<<"AZAD2";
      	if(root->right==NULL)
      		root=root->left;
        if(root->left==NULL)
      		root=root->right;
      		cout<<"AZAD3";
      	free(temp);
      }
   }
    cout<<"test1"<<endl;
  return root;
 }

int main(){
binaryTree *root=createNode(4);
 root->left=createNode(2);
 root->right=createNode(6);

 root->left->left=createNode(1);
 root->left->right=createNode(3);
 root->right->left=createNode(5);
 root->right->right=createNode(7);
 preOrderTraverse(root);         //4 2 1 3 6 5 7
 cout<<endl;
 Delete(root,7);
 preOrderTraverse(root);
  return 0;
}
