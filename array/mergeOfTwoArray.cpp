//Merge two array of different size using O(1) space
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

void solve(){
  ll n,m,last;
  cin>>n>>m;
  vll ar1(n),ar2(m);
  f(i,0,n)cin>>ar1[i];
  f(i,0,m)cin>>ar2[i];
  for(int i=m-1;i>=0;i--){
    last=ar1[n-1];
    int j=n-2;
    while(j>=0 && ar1[j]>ar2[i]){
      ar1[j+1]=ar1[j];
      j--;
    }
    if(ar2[i]<last ){
      ar1[j+1]=ar2[i];
      ar2[i]=last;
    }
  }
  for(auto it:ar1)cout<<it<<" ";cout<<endl;
  for(auto it:ar2)cout<<it<<" ";cout<<endl;
}

int main(){