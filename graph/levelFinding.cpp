#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define mod 1000000
void BFS(list<ll>adj[],int V,vll &level){
  queue<pair<int,int>>qu;
  vll vis(V+1,-1);
  qu.push({1,0});  
  vis[1]=1;
  level[1]=0;
  while(!qu.empty()){
    int cur=qu.front().first;
    int l=qu.front().second;
    qu.pop();
    for(auto it:adj[cur]){
      if(vis[it]==-1){
        level[it]=l+1;
        qu.push({it,l+1});
        vis[it]=1;
      }
    }
  }
}

int main(){
  int V,E,a,b;
  cin>>V>>E;
  list<ll>adj[V+1];
  for(int i=1;i<=E;i++){
   cin>>a>>b;
   adj[a].push_back(b);
   adj[b].push_back(b);
  }
  vll level(V+1,-1);
  BFS(adj,V,level);
  for(int i=1;i<=V;i++){
    cout<<i<<" ->"<<level[i]<<endl;
  }
  return 0;
}