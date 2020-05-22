#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll bfs(ll s,list<ll>adj[],ll V,ll &cont){
  vector<ll>visited(V+1,-1);
  queue<pair<ll,ll>>qq;
  qq.push(make_pair(s,0));
  visited[s]=1;

  ll ans,level=0;
  pair<ll,ll> cur;
  while(!qq.empty()){
    cur=qq.front();
    qq.pop();
    ans=cur.first;
    level=cur.second+1;
    for(auto it:adj[cur.first]){
      if(visited[it]==-1){
        qq.push(make_pair(it,level));
        visited[it]=1;
      }
      
    }
  }
  cont=cur.second;
  return ans;
}

int main(){
  ll E,V,a,b;
  cin>>V>>E;
  list<ll>adj[V+1];
  for(int i=1;i<=E;i++){
    cin>>a>>b;
    adj[a].push_back(b); 
    adj[b].push_back(a); 
  }
  ll cont =0;
  ll start=bfs(1,adj,V,cont);
 
  bfs(start,adj,V,cont);
   cout<<cont;
  
  return 0;
}

