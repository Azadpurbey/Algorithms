#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int t2Sum(TreeNode* A, int B){  // find two element whose sum = target
    if(A==NULL)return 0;
    stack<TreeNode*>left,right;
    TreeNode* temp=A;
    while(temp!=NULL){
        left.push(temp);
        temp=temp->left;
    }
    temp=A;
    while(temp!=NULL){
        right.push(temp);
        temp=temp->right;
    }
    
    while(!left.empty() && !right.empty()){
        TreeNode* temp1=left.top();
        TreeNode* temp2=right.top();
        if(temp1==temp2)return 0;
        int x=temp1->val+temp2->val;
        if(x==B)return 1;
        else if(x<B){
            left.pop();
            temp1=temp1->right;
            while(temp1!=NULL){
                left.push(temp1);
                temp1=temp1->left;
            }
        }
        else{
            right.pop();
            temp2=temp2->left;
            while(temp2!=NULL){
                right.push(temp2);
                temp2=temp2->right;
            }
        }
    }
    return 0;
}

int main(){
    // 
}