#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define si set<int>
#define pii pair<int,int>
#define mii map<int,int>
#define vi vector<int>
// class compare{
//   public:
//   bool operator()(pii a,pii b){
//     return a.first>b.first;
//   }
// };
ll Mst(list<pii>adj[],ll V){
  ll ans=0;
  pii cur;
  priority_queue<pii,vector<pii>,greater<pii>>pq;
  vi visited(V+1,0);
  pq.push(make_pair(0,1));

  while(!pq.empty()){
    cur=pq.top();
    pq.pop();
    if(visited[cur.second]==0){
      visited[cur.second]=1;
      // cout<<cur.first<<endl;
        ans+=cur.first;
        for(auto it:adj[cur.second]){
          if(visited[it.second]==0)
              pq.push(it);
        }  
    }
  }
  return ans;
}

int main(){
  ll V,E,a,b,w;
  cin>>V>>E;
  list<pii> adj[V+1];
  for(ll i=0;i<E;i++){
    cin>>a>>b>>w;
    adj[a].push_back(make_pair(w,b));
    adj[b].push_back(make_pair(w,a));
  }

  ll ans=Mst(adj,V);
   cout<<ans;
  return 0;
} 