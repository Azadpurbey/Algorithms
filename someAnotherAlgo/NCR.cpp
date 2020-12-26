#include<bits/stdc++.h>
  #define f(i,a,b) for(ll i=a;i<b;i++)
  #define fr(i,a,b) for(ll i=a;i>b;i--)  
  #define ll long long
  #define vll vector<long long>
  #define mll map<ll,ll>
  #define sll set<ll>
  #define pll pair<ll>
  #define pb(x) push_back(x)
  #define F first
  #define S second
  #define print(v) for(auto it:v)cout<<it<<" ";cout<<endl
  #define mod 1000000007 //10^9 +7
  #define it(v) v.begin(),v.end()
  #define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  #define InputOutput freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);            
using namespace std;

void NCR(){
  ll N,M;       //ncr=(n-1)C(r-1) +(n-1)Cr
  cin>>N>>M;
  ll ar[N+1][M+1];
  for(int n=1;n<=N;n++)ar[n][0]=1,ar[n][n]=1;
  for(int n=2;n<=N;n++){
    for(int r=1;r<n;r++)ar[n][r]=(ar[n-1][r-1]+ar[n-1][r])%mod;
  }

  for(int n=1;n<=N;n++){
    for(int r=0;r<=n;r++){
      cout<<n<<" C "<<r<<"="<<ar[n][r]<<endl;
    }
  }
}


int main(){
  #ifndef ONLINE_JUDGE 
    InputOutput
  #endif
  IOS
  ll q=1;
  //cin>>q;
  while(q--){
    NCR();
  }
  return 0;
} 