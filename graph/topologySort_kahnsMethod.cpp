#include <bits/stdc++.h>
using namespace std;
#define ll long long


vector<ll> topologySort(list<ll>adj[],ll V,vector<ll>degree){
  vector<ll> visited(V+1,-1);
  vector<ll>ans;
  queue<ll>qq;
  for(ll i=1;i<=V;i++)
    if(degree[i]==0)
      qq.push(i);
     
  while(!qq.empty()){
    ll cur=qq.front();qq.pop();
    ans.push_back(cur);
    for(auto it:adj[cur]){
      degree[it]--;
      if(degree[it]==0){
        qq.push(it);
      }
    }
  }
  return ans;
}
int main(){
  
    ll E,V,a,b;
    cin>>V>>E;
    list<ll>adj[V+1];
    vector<ll>degree(V+1,0);
    for(int i=1;i<=E;i++){
      cin>>a>>b;
      degree[b]++;
      adj[a].push_back(b); 
    }
    vector<ll>ans=topologySort(adj,V,degree);
    cout<<endl;
    if(ans.size()<V)cout<<"Not possible";
    else{
        for(auto it:ans)cout<<it<<" ";
    }

  return 0;
} 