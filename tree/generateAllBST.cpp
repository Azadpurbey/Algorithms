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
    vector<TreeNode*> helper(int start,int end){
        vector<TreeNode*>ans;
        if(start >end)return {NULL};
        for(int i=start;i<=end;i++){
            vector<TreeNode*> left=helper(start,i-1);
            vector<TreeNode*> right=helper(i+1,end);
            for(int j=0;j<left.size();j++){
                TreeNode *l=left[j];
                for(int k=0;k<right.size();k++){
                    TreeNode *r=right[k];
                    TreeNode* temp=new TreeNode(i);
                    temp->left=l;
                    temp->right=r;
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)return {};
       vector<TreeNode*>ans= helper(1,n);
        return ans;
    }
};
int main(){
    // craete tree and test
}