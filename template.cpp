#ifndef AZAD   
 #include<bits/stdc++.h>
  #define f(i,a,b) for(ll i=a;i<b;i++) 
  #define ll long long
  #define endl "/n"
  #define vll vector<ll>
  #define vv vector<vll>
  #define mll map<ll,ll>
  #define sll set<ll>
  #define pll pair<ll,ll>
  #define pb push_back
  #define F first
  #define S second
  #define print(v) for(auto it:v)cout<<it<<" ";cout<<endl;
  #define fill(dp,a) memset(dp,a,sizeof(dp))
  #define all(v) v.begin(),v.end()
  #define allr(v) v.rbegin(),v.rend()
  #define p2(x,y) cout<<"x="<<x<<" y="<<y<<endl
  #define p1(x) cout<<"x="<<x<<endl
  #define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  #define InputOutput freopen("input.txt","r",stdin);
  const ll mod = 1e9+7;//10^9+7
  const ll INF=9*1e18;  // 9*10^18
 using namespace std; 
#endif

vector<bool> prime(100000000,true);
void create_prime(){
  prime[0]=prime[1]=false;
  for(int i=2;i*i<100000000;i++){
    if(prime[i]){
      for(int j=i;i*j<100000000;j++)
        prime[i*j]=false;
    }
  }
}

ll Ceil(ll a,ll b){
  return (a+(b-1))/b;
}

ll exp(ll x,ll n,ll m){
  ll res=1;
  while(n>0){
    if(n&1)
    res=(res*x)%m;
    x=(x*x)%m;
    n/=2;
  }
return res;
}


void dfs(ll root,list<ll> adj[],vll &vis){ 
  vis[root]=1;
  cout<<root<<" ";
  for(auto it:adj[root]){
    if(vis[it]==-1){
      vis[it]=1;
      dfs(it,adj,vis);
    }
  }
}

void graphInput(){
  ll V,E,a,b;
  cin>>V>>E;
  list<ll>adj[V];
  vll vis(V,-1);
  f(i,0,E){
    cin>>a>>b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
}

void NCR(ll N){
  ll ar[N+1][N+1];
  for(int n=1;n<=N;n++)ar[n][0]=1,ar[n][n]=1;
  for(int n=2;n<=N;n++){
    for(int r=1;r<n;r++)ar[n][r]=(ar[n-1][r-1]+ar[n-1][r])%mod;
  }
}

void solve(){
  cout<<__gcd(525,63)<<"done";
}

int main(){
  #ifndef ONLINE_JUDGE 
    InputOutput
  #endif
  double _tBeg=clock();
  IOS
  ll q=1;
  //cin>>q;
  while(q--){
    solve();
  }
  #ifndef ONLINE_JUDGE
    double _tEnd=clock();
    printf("total time %.6f\n",(_tEnd-_tBeg)/CLOCKS_PER_SEC);
  #endif
  return 0;
}  