#include<bits/stdc++.h> 
#define ll long long
#define vll vector<ll>
#define pb push_back
using namespace std;     
stack<ll>st;
void dfs(ll root,list<ll> adj[],vll &vis,vll &hold){ 
  vis[root]=1;
  hold.pb(root);
  for(auto it:adj[root]){
    if(vis[it]==-1){
      vis[it]=1;
      dfs(it,adj,vis,hold);
    }
  }
  st.push(root);
}

int main(){
  freopen("input.txt","r",stdin);
  ll V,E,a,b;
  cin>>V>>E;
  list<ll>adj1[V+1],adj2[V+1];
  vll vis(V+1,-1),hold;
  for(int i=0;i<E;i++){
    cin>>a>>b;
    adj1[a].pb(b);
    adj2[b].pb(a);  // reverse graph
  }
  for(int i=1;i<=V;i++){
    if(vis[i]==-1)dfs(i,adj1,vis,hold);
  }
  for(int i=0;i<=V;i++)vis[i]=-1;
  vector<vll>ans;
  stack<ll>st1=st;
  while(!st1.empty()){
    ll cur=st1.top();st1.pop();
    vll hold1;
    if(vis[cur]==-1){
      dfs(cur,adj2,vis,hold1);
      ans.pb(hold1);
    }
  }
  for(auto it:ans){
    for(auto it1:it)cout<<it1<<" ";
    cout<<endl;
  }
  return 0;
}