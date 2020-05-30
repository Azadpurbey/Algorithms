#ifndef AZAD   
 #include<bits/stdc++.h>
  #define f(i,a,b) for(ll i=a;i<b;i++)
  #define fr(i,a,b) for(ll i=a;i>b;i--)  
  #define ll long long
  #define vll vector<ll>
  #define vv vector<vll>
  #define mll map<ll,ll>
  #define sll set<ll>
  #define pll pair<ll,ll>
  #define pb(x) push_back(x)
  #define F first
  #define S second
  #define print(v) for(auto it:v)cout<<it<<" ";cout<<endl;
  #define all(v) v.begin(),v.end()
  #define allr(v) v.rbegin(),v.rend()
  #define p4(x,y,z,w) cout<<"x="<<x<<" y="<<y<<" z="<<z<<" w="<<w<<endl
  #define p3(x,y,z) cout<<"x="<<x<<" y="<<y<<" z="<<z<<endl
  #define p2(x,y) cout<<"x="<<x<<" y="<<y<<endl
  #define p1(x) cout<<"x="<<x<<endl
  #define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  #define InputOutput freopen("input.txt","r",stdin);//freopen("output.txt","w",stdout);
  const int mod = 1000000007;//10^9+7
 using namespace std; 
#endif

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
  IOS
  ll q=1;
  //cin>>q;
  while(q--){
    solve();
  }
  return 0;
}  