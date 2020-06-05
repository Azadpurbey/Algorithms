#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
  TreeNode* helper(vector<int>& inorder,int is,int ie, vector<int>& postorder,int ps,int pe,map<int,int>&mp){
    TreeNode *temp=new TreeNode();
    if(is>ie || ps>pe)return NULL;
    temp->val=postorder[pe];
    int mid=mp[temp->val];
    TreeNode *left=helper(inorder,is,mid-1,postorder,ps,ps+mid-is-1,mp);
    TreeNode *right=helper(inorder,mid+1,ie,postorder,ps+mid-is,pe-1,mp);
    temp->left=left;
    temp->right=right;  
    return temp;  
  }
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
    TreeNode *root=NULL;
    int n=inorder.size();
    if(n==0)return root;
    map<int,int>mp;
    for(int i=0;i<inorder.size();i++){
      mp[inorder[i]]=i;
    }
    root=helper(inorder,0,n-1,postorder,0,n-1,mp);
    return root;
  }
};

int main(){
  Solution ss;
  vector<int>inorder={9,3,15,20,7};
  vector<int>postorder={9,15,7,20,3};
  TreeNode* root=ss.buildTree(inorder,postorder);
  return 0;
}
/*
    3
   / \
  9  20
    /  \
   15   7
*/  