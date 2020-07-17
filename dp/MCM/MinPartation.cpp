#include<bits/stdc++.h> // Min cut required to make all substring a palindrome
using namespace std;
bool isPalindrome(string &s,int i,int j){
  for(int a=i,b=j;a<b;a++,b--){
    if(s[a]!=s[b])return false;
  }
  return true;
}

int minCut(string &s,int i,int j,vector<vector<int>>&dp){
  if(i>=j)return 0;
  if(dp[i][j]!=-1)return dp[i][j];
  if(isPalindrome(s,i,j))return 0;
  int Min=INT_MAX;
  for(int k=i;k<j;k++){
    int temp=minCut(s,i,k,dp)+minCut(s,k+1,j,dp)+1;
    Min=min(Min,temp);
  }
  dp[i][j]=Min;
  return dp[i][j];
}
int main(){
  freopen("input.txt","r",stdin);
  string s;
  cin>>s;
  int n=s.length();
  vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
  cout<<minCut(s,0,n-1,dp);
  return 0;
}

