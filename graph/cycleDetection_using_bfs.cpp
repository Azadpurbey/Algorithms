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

bool isCycle(ll root,list<ll> adj[],vll &vis){
  vis[root]=1;
  queue<ll>qu;
  qu.push(root);
  while(!qu.empty()){
    ll cur=qu.front();
    cout<<cur;
    qu.pop();
    for(auto it:adj[cur]){
        if(vis[it]==0)return true;
        if(vis[it]==-1){
          vis[it]=0;
          qu.push(it);
        }
    }
    vis[cur]=1;
  }
  return false;
}


int main(){
  freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
  IOS
  ll V,E,a,b;
  cin>>V>>E;
  list<ll>adj[V];
  vll vis(V,-1);
  f(i,0,E){
    cin>>a>>b;
    adj[a].pb(b);
    adj[b].pb(a);
  }

  if(isCycle(0,adj,vis))cout<<"Cycle found"<<endl;
  else cout<<"No cycle"<<endl;
  return 0;
}