#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i,a,b) for(int i=a;i<b;i++)

void dfs(int s,list<int>adj[],int V,int* visited){
    visited[s]=1;
  for(auto it:adj[s]){
    if(visited[it]==-1){
      dfs(it,adj,V,visited);
    }
  }
}

int no_of_component(list<int>adj[],int V){
  int v1[V+1];
    memset(v1,-1,sizeof(v1));    
  int cont=0;
  for(int i=1;i<=V;i++){
      if(v1[i]==-1){
        cont++;
        dfs(i,adj,V,v1);
      }
  }
  return cont;
}

int NoOfCycle(list<int>adj[],int start,int* visited){
  int cont=0;
  queue<int>qq;
  qq.push(start);
  visited[start]=0;
  while(!qq.empty()){
    int cur=qq.front();
    qq.pop();
    for(auto it:adj[cur]){
      if(visited[it]==-1){
        qq.push(it);
        visited[it]=0;
      }    
      else if(visited[it]==0)cont++;      
    }    
    visited[cur]=2;
  }

  return cont;
}

int main(){
  ll q;
  cin>>q;
  while(q--){
    ll V,E,cLib,cRoad,a,b,x,y;
    cin>>V>>E;
        list<ll>adj[V+1];
        for(ll i=0;i<E;i++){
         cin>>a>>b;
          adj[a].push_back(b);
          adj[b].push_back(a);
        }
        int visited[V+1];
        memset(visited,-1,sizeof(visited));
          x=no_of_component(adj,V);
        y=NoOfCycle(adj,1,visited);
        cout<<"component "<<x<<" cycle "<<y<<endl; 
  }
  return 0;
} 
