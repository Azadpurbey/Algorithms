#include <bits/stdc++.h>
using namespace std;
#define ll long long
stack<ll>ss;
void dfs(ll s,list<ll>adj[],vector<ll> &visited){
  visited[s]=1;
  for(auto it:adj[s]){
      if(visited[it]==-1)
       dfs(it,adj,visited);
  }
    ss.push(s);
}

int main(){
  
    ll E,V,a,b;
    cin>>V>>E;
    list<ll>adj[V+1];
    for(int i=1;i<=E;i++){
      cin>>a>>b;
      adj[a].push_back(b); 
    }
    vector<ll> visited(V+1,-1);
    dfs(1,adj,visited);
    for(auto i=0;i<V;i++)cout<<ss.top()<<" ",ss.pop();

  return 0;
} 