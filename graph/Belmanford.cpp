#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define si set<int>
#define pii pair<int,int>
#define mii map<int,int>
#define vi vector<int>
struct data{
  int a,b,w;
};
void Belmanford(vector<data> edge,int V,vector<int>&dis){
  data hold;
  for(int i=1;i<V;i++){
    for(auto it:edge){
       int u=it.a,v=it.b,wt=it.w;
       if(dis[v]>dis[u]+wt)dis[v]=dis[u]+wt;
    }
  }

      for(auto it:edge){
       int u=it.a,v=it.b,wt=it.w;
       if(dis[v]>dis[u]+wt)cout<<"Negative cycle is present so the ans may not correct"<<endl;
    }
}

int main(){
  ll V,E,a,b,w;
  cin>>V>>E;
  data hold;
  vector<data>edge;
  for(ll i=0;i<E;i++){
    cin>>hold.a>>hold.b>>hold.w;
    ar.pb(hold);
  }
   vector<int>dis(V+1,INT_MAX);
   int source=1;
   dis[source]=0;
   Belmanford(edge,V,dis);
   for(int i=1;i<=V;i++)
     cout<<i<<"->  "<<dis[i]<<endl;
  return 0;
} 