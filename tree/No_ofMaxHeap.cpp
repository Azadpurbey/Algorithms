#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007
#define ll long long
ll ar[100][100];
int getleft(int n){
  int a=1,sum=0;
  while(n>0){
    if(n>=a){
      sum+=a;
      n-=2*a;
      a*=2;
    }
    else{
      sum+=n;
      n=0;
    }
  }
  return sum;
}

void NCR(){
  int N=100;
  memset(ar,0,sizeof(ar));
  for(int n=1;n<=N;n++)ar[n][0]=1,ar[n][n]=1;
  for(int n=2;n<=N;n++){
    for(int r=1;r<n;r++)ar[n][r]=(ar[n-1][r-1]+ar[n-1][r])%mod;
  }
}

int heap(int n){
  if(n<=2)return 1;
  vector<ll>dp(n+1,0);
  dp[0]=dp[1]=dp[2]=1;

  for(int i=3;i<=n;i++){
    int left=getleft(i-1);
    int right=i-left-1;
    ll hold=(dp[left]*dp[right])%mod;
    dp[i]=(ar[i-1][left]*hold)%mod;
  }
  return dp[n];
}

int main() { 
  NCR();
  int n;
  cin>>n;
  cout<<heap(30);
  return 0;
} 