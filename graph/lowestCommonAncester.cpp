#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>bfs(ll root,list<ll>adj[],ll V){
vector<ll>parents(V+1,-1);
 queue<ll>qq;
 vector<ll> visited(V+1,-1);
 qq.push(root);
 visited[root]=1;
 while(!qq.empty()){
  ll cur=qq.front();
//   cout<<cur<<" ";
  qq.pop();
  for(auto it:adj[cur]){
    if(visited[it]==-1){
      parents[it]=cur;    
      qq.push(it);
      visited[it]=1;
    }  
  }
    
 }
 return parents;
}






int main(){
  ll E,V,a,b,ans;
  cin>>V>>E;
  list<ll>adj[V+1];
  for(int i=1;i<=E;i++){
    cin>>a>>b;
    adj[a].push_back(b); 
    adj[b].push_back(a); 
  }
  vector<ll>parents=bfs(1,adj,V);
  cin>>a>>b;
  vector<ll>match1,match2;
  match1.push_back(a);
  while(a!=-1){
      match1.push_back(parents[a]);
      a=parents[a];
  }
  match2.push_back(b);
  while(b!=-1){
      match2.push_back(parents[b]);
      b=parents[b];
  }
//   for(auto it:match1)cout<<it<<" ";
//   cout<<endl;
//   for(auto it:match2)cout<<it<<" ";
//   cout<<endl;
  
  auto it1=match1.rbegin();
  auto it2=match2.rbegin();
  while( it1!=match1.rend() &&*it1==*it2){
      ans=*it1;
      it1++,it2++;
  }
  cout<<ans;
  return 0;
}