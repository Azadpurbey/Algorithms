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
  #define pb push_back
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
  const ll mod = 1e9+7;//10^9+7
  const ll INF=9*1e18;  // 9*10^18
 using namespace std; 
#endif
struct DSU{
	vll dsu,freq;
	DSU(ll n){
		for(int i=0;i<=n;i++){
			dsu.pb(i);
			freq.pb(1);
		}		
	}
	ll root(ll a){
		if(dsu[a]==a)return dsu[a];
		dsu[a]=root(dsu[a]);  // optimisation
		return dsu[a];
	}
	void Union(ll a,ll b){
		ll a_root=root(a);
		ll b_root=root(b);
    if(a_root==b_root)return;
		if(freq[b_root]<freq[a_root])   //optimization
			swap(a_root,b_root);
		dsu[a_root]=b_root;
		freq[b_root]+=freq[a_root];
	}
};

int main(){
  freopen("input.txt","r",stdin);
  ll V,E,a,b;
  cin>>V;
  E=V-1;
  list<ll>adj[V+1];
  vll vis(V+1,-1);
  vll dsu(V+1),freq(V+1,1);
  f(i,0,V+1){
    dsu[i]=i;
  }
  for(int i=0;i<E;i++){
    cin>>a>>b;
    Union(dsu,freq,a,b);
    adj[a].pb(b);
    adj[b].pb(a);
  }
  print(dsu);
  print(freq);

  return 0;
}
