#include<bits/stdc++.h>           // Expression evaluation to true
using namespace std;
#define mod 1003
int dp[160][160];

int solve(int N,int E){
  if(N<=1)return N;
  if(E==1)return N;
  int Min=INT_MAX;
  for(int k=1;k<=N;k+=1){
    int x=solve(k-1,E-1);  // break
    int y=solve(N-k,E);
    int temp=max(x,y);
    Min=min(Min,temp);
  }
  dp[N][E]=Min;
  return dp[N][E];
}

int main(){
  freopen("input.txt","r",stdin);
  memset(dp,-1,sizeof(dp));
  int N,E;
  cin>>N>>E;
  cout<<solve(N,E);

  return 0;
}

