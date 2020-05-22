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
list<pll>adj[100009];
ll V,flag=0;
vll Dijkstra(){
  vll dis(V+1,-1),parent(V+1,-1);
  dis[1]=0;
   priority_queue<pll,vector<pll>,greater<pll>>qu;
  //queue<pll>qu;
  qu.push({0,1});
  while(!qu.empty()){
   pll cur=qu.top();
  //pll cur=qu.front();
    qu.pop();
    for(auto it:adj[cur.S]){
      ll wt=it.F,node=it.S;
      if(dis[node]>(wt+cur.F) || dis[node]==-1){
        parent[it.S]=cur.S;
        dis[node]=wt+cur.F;
        qu.push({dis[node],node});
      }
    }
  }
  if(dis[V]==-1)flag=1;
  return parent;
}
void solve(){
  ll E,a,b,w;
  cin>>V>>E;
  f(i,0,E){
    cin>>a>>b>>w;
    adj[a].push_back({w,b});
    adj[b].push_back({w,a});
  }
  vll parent=Dijkstra();   
                        
  if(flag==1)cout<<-1;  // printing path fron source to destination
  else{
    vll ans;
    ll hold=V;
    while(hold!=-1){
        ans.pb(hold);
        hold=parent[hold];
    }
    for(auto it=ans.rbegin();it!=ans.rend();it++)cout<<*it<<" ";
  }
}

int main(){
  #ifndef ONLINE_JUDGE 
    InputOutput
  #endif
  IOS
  ll q=1;
  //cin>>q;
  while(q--){
    solve();
  }
  return 0;
}  
