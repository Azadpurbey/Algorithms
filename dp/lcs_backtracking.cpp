#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main(){
  ll l1,l2;
  string s1,s2;
  cin>>s1>>s2;
  l1=s1.length();
  l2=s2.length();
  vector<vector<ll>>dp(l1+1,vector<ll>(l2+1,0)); 
     
  for(int i=1;i<=l1;i++){
    for(int j=1;j<=l2;j++){
      if(s1[i-1]==s2[j-1])dp[i][j]=1+dp[i-1][j-1];
      else{
        int b= dp[i-1][j];
        int c= dp[i][j-1];
        dp[i][j]=max(b,c);
      }
    }
  } 
  cout<<dp[l1][l2]<<endl;  // Max length
 
  ll a=l1,b=l2;             //  BACKTRACKING
  string s_ans="";
  while(a>0 && b>0){
    if(dp[a][b]==dp[a-1][b])a--;
    else if(dp[a][b]==dp[a][b-1])b--;
    else{
      s_ans=s2[b-1]+s_ans;
      a--,b--;              
    }
  }  
  cout<<s_ans<<endl;    // Common subsequence
  return 0;
} 