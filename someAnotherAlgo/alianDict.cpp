#ifndef AZAD   
  #include<bits/stdc++.h>
  #define f(i,a,b) for(ll i=a;i<b;i++)
  #define fr(i,a,b) for(ll i=a;i>b;i--)  
  #define ll long long
  #define vll vector<ll>
  #define vv vector<vll>
  #define mll map<ll,ll>
  #define sll set<ll>
  #define pll pair<ll,ll>
  #define pb(x) push_back(x)
  #define F first
  #define S second
  #define print(v) for(auto it:v)cout<<it<<" ";cout<<endl;
  #define fill(v,a) memset(v,a,sizeof(v))
  #define all(v) v.begin(),v.end()
  #define allr(v) v.rbegin(),v.rend()
  #define p3(x,y,z) cout<<"x="<<x<<" y="<<y<<" z="<<z<<endl
  #define p2(x,y) cout<<"x="<<x<<" y="<<y<<endl
  #define p1(x) cout<<"x="<<x<<endl
  #define p(s,x) cout<<s<<" "<<x<<endl
  #define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  #define InputOutput freopen("input.txt","r",stdin);//freopen("output.txt","w",stdout);
  const int mod = 1000000007;//10^9+7
  const ll INF=9000000000000000000;  // 9*10^18
  using namespace std; 
#endif
void dfs(int root,list<int>adj[],vector<int>&vis,stack<int>&stk,int &flag){
  vis[root]=0;
  if(flag==1)return;
  for(auto it:adj[root]){
    if(vis[it]==-1){
      vis[it]=0;
      dfs(it,adj,vis,stk,flag);
    }
    else if(vis[it]==0){
      flag=1;
      return;
    }
  }
  vis[root]=1;
  stk.push(root);
}
void solve(){
  ll n;
  cin>>n;
  vector<string>ar(n);
  for(int i=0;i<n;i++){
    cin>>ar[i];
  }
  list<int>adj[26];
  for(int i=1;i<n;i++){
    int len=min(ar[i].length(),ar[i-1].length());
    int flag=0;
    for(int j=0;j<len;j++){
      if(ar[i][j]!=ar[i-1][j]){
        adj[ar[i-1][j]-'a'].push_back(ar[i][j]-'a');
        flag=1;
        break;
      }
    }
    if(flag==0){
      if(ar[i-1].length()>len){
        cout<<"Impossible"<<endl;
        return;
      }
    }
  }
  stack<int>stk;
  vector<int>vis(26,-1);
  for(int i=0;i<26;i++){
    if(vis[i]==-1){
      int flag=0;
      dfs(i,adj,vis,stk,flag);
      if(flag==1){
        cout<<"Impossible"<<endl;
        return;
      }
    }
  }
  while(!stk.empty()){
    cout<<char(stk.top()+'a');
    stk.pop();
  }
  cout<<endl;
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