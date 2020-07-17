#include<bits/stdc++.h>           // Expression evaluation to true
using namespace std;
#define mod 1003
int dp[160][160][2];

int expression_evaluation(string &s,int i,int j,bool req){
  if(i>j)return 0;
  if(dp[i][j][req]!=-1)return dp[i][j][req];
  if(i==j){
    if(s[i]=='T' && req==true)return 1;
    else if(s[i]=='F' && req==false)return 1;
    return 0;
  }

  int temp=0;
  for(int k=i;k<j;k+=2){
    int lt=expression_evaluation(s,i,k,true);
    int lf=expression_evaluation(s,i,k,false);
    int rt=expression_evaluation(s,k+2,j,true);
    int rf=expression_evaluation(s,k+2,j,false);
    if(req){
      if(s[k+1]=='|')temp=(temp+lt*rt +lt*rf+lf*rt)%mod;
      else if(s[k+1]=='&')temp=(temp+lt*rt)%mod;
      else{
        temp=(temp+lt*rf+lf*rt)%mod;
      }
    }
    else{
      if(s[k+1]=='|')temp=(temp+lf*rf)%mod;
      else if(s[k+1]=='&')temp=(temp+lt*rf +lf*rt +lf*rf)%mod;
      else{
        temp=(temp+lt*rt+lf*rf)%mod;
      }
    }
  }
  dp[i][j][req]=temp;
  return dp[i][j][req];
}

int main(){
  freopen("input.txt","r",stdin);
  memset(dp,-1,sizeof(dp));
  string s;
  cin>>s;
  int n=s.length();
  cout<<expression_evaluation(s,0,n-1,true);
  // cout<<endl;
  // for(int i=0;i<6;i+=2){
  //   for(int j=0;j<6;j+=2)cout<<dp[i][j][1]<<" ";
  //   cout<<endl;
  // }
  return 0;
}

