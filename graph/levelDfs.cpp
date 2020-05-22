#include<bits/stdc++.h>
  #define f(i,a,b) for(ll i=a;i<b;i++)
  #define fr(i,a,b) for(ll i=a;i>b;i--)  
  #define ll long long
  #define vll vector<long long>
  #define mll map<ll,ll>
  #define sll set<ll>
  #define pll pair<long long,long long>
  #define pb(x) push_back(x)
  #define F first
  #define S second
  #define print(v) for(auto it:v)cout<<it<<" ";cout<<endl;
  #define mod 1000000007  //10^9+7
  #define it(v) v.begin(),v.end()
  #define itr(v) v.rbegin(),v.rend()
  #define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  #define InputOutput freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
using namespace std;
vll level(1000,-1),child(1000,0);
void dfs(ll root,ll l, list<ll> adj[]){ 
  level[root]=l;
  child[root]=1;
  for(auto it:adj[root]){
    if(level[it]==-1){
      level[it]=l+1;
      dfs(it,l+1,adj);
      child[root]+=child[it];
    }
  }
}

void solve(){
  ll V,E,a,b;
  cin>>V>>E;
  list<ll>adj[V+1];
  f(i,0,E){
    cin>>a>>b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  dfs(1,0,adj);
  cout<<"V"<<" L "<<"C"<<endl;
  for(int i=1;i<=V;i++){
    cout<<i<<" "<<level[i]<<" "<<child[i]-1<<endl;
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
    solve();
  }
  return 0;
} 