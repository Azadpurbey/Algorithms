#include<bits/stdc++.h>         // Max rect area in binary matrix with ones
using namespace std;

int findRectangleArea(vector<int>&ar,int n){
  vector<int> right(n),left(n);
  stack<int>stk;
  for(int i=n-1;i>=0;i--){
    while(!stk.empty() && ar[stk.top()]>=ar[i]){
      stk.pop();
    }
    if(stk.empty())right[i]=n;
    else right[i]=stk.top();
    stk.push(i);
  }
  while(!stk.empty())stk.pop();
  for(int i=0;i<n;i++){
    while(!stk.empty() && ar[stk.top()]>=ar[i]){
      stk.pop();
    }
    if(stk.empty())left[i]=-1;
    else left[i]=stk.top();
    stk.push(i);
  }
  int Max=INT_MIN;
  for(int i=0;i<n;i++){
    int temp=(right[i]-left[i]-1)*ar[i];
    Max=max(Max,temp);
  }
  return Max;
}

int main(){
  freopen("input.txt","r",stdin);
  int R,C;
  cin>>R>>C;
  vector<vector<int>>mat(R,vector<int>(C));
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++)cin>>mat[i][j];
  }
  for(int i=1;i<R;i++){
    for(int j=0;j<C;j++){
      if(mat[i][j]!=0){
        mat[i][j]+=mat[i-1][j];
      }
    }
  }
  int Max=INT_MIN;
  for(int i=0;i<R;i++){
    int temp=findRectangleArea(mat[i],C);
    Max=max(Max,temp);
  }
  cout<<Max<<endl;
  return 0;
}

