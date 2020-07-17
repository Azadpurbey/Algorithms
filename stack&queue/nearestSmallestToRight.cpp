#include<bits/stdc++.h>   // Nearest smaller element in an array in right dir
using namespace std;

int main(){
  freopen("input.txt","r",stdin);
  int n;
  cin>>n;
  vector<int>ar(n);
  for(int i=0;i<n;i++)cin>>ar[i];
  vector<int>ans(n);
  stack<int>stk;
  for(int i=n-1;i>=0;i--){
    while(!stk.empty() && stk.top()>=ar[i]){
      stk.pop();
    }
    if(stk.empty())ans[i]=INT_MIN;
    else ans[i]=stk.top();
    stk.push(ar[i]);
  }
  for(auto it:ans)cout<<it<<" ";

  return 0;
}

