#include<bits/stdc++.h>
  #define f(i,a,b) for(ll i=a;i<b;i++)
  #define fr(i,a,b) for(ll i=a;i>b;i--)  
  #define ll long long
  #define vll vector<long long>
  #define mll map<ll,ll>
  #define sll set<ll>
  #define pll pair<long long,long long>
  #define pb(x) push_back(x)
  #define F first
  #define S second
  #define print(v) for(auto it:v)cout<<it<<" ";cout<<endl;
  #define mod 1000000007//10^9+7
  #define it(v) v.begin(),v.end()
  #define itr(v) v.rbegin(),v.rend()
  #define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  #define InputOutput freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
using namespace std;

vll Dijkstra(int st,ll V,list<pll>adj[]){
  vll dis(V+1,INT_MAX);
  dis[st]=0;
  priority_queue<pll,vector<pll>,greater<pll>>qu;
  qu.push({0,st});
  while(!qu.empty()){
    pll cur=qu.top();
    qu.pop();
    for(auto it:adj[cur.S]){
      ll edge_wt=it.F;
      ll new_dis=dis[cur.S]+edge_wt;
      if(new_dis<dis[it.S]){
        dis[it.S]=new_dis;
        qu.push({dis[it.S],it.S});
      }
    }
  }
  return dis;
}

int main(){
  freopen("input.txt","r",stdin);
  ll E,V,a,b,wt;
  cin>>V>>E;
  list<pll>adj[V+1];
  f(i,0,E){
    cin>>a>>b>>wt;
    adj[a].push_back({wt,b});
    adj[b].push_back({wt,a});
  }
  vll shortest_distance=Dijkstra(0,V,adj); 
  for(int i=0;i<V;i++){
    cout<<i<<" distance "<<shortest_distance[i]<<endl;
  }  
  return 0;
}

