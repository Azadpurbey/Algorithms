#include<bits/stdc++.h>
  #define f(i,a,b) for(int i=a;i<b;i++)
  #define fr(i,a,b) for(int i=a;i>b;i--)  
  #define ll long long
  #define vll vector<long long>
  #define mll map<ll,ll>
  #define sll set<ll>
  #define pll pair<long long,long long>
  #define pb(x) push_back(x)
  #define F first
  #define S second
  #define print(v) for(auto it:v)cout<<it<<" "
  #define mod 1000000007  //10^9+7
  #define it(v) v.begin(),v.end()
  #define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

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

int main(){
  freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
  IOS
  ll V,E,a,b;
  cin>>V>>E;
  list<ll>adj[V+1];
  vll vis(V+1,-1);
  f(i,0,E){
    cin>>a>>b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  dfs(1,adj,vis);
  return 0;
}