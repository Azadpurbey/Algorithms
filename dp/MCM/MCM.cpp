#ifndef AZAD   
 #include<bits/stdc++.h>
  #define f(i,a2,a3) for(ll i=a2;i<a3;i++)
  #define fr(i,a2,a3) for(ll i=a2;i>a3;i--)  
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
  #define fill(v,a2) memset(v,a2,sizeof(v))
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
int dp[1001][1001];
ll MCM(int i,int j,vll &ar){
  if(dp[i][j]!=0)return dp[i][j];
  if(i>=j)return 0;
  ll Min=INT_MAX;
  for(int k=i;k<j;k++){
    ll x=MCM(i,k,ar),y=MCM(k+1,j,ar);
    //dp[i][k]=x,dp[k+1][j]=y;
    ll temp=x+y+ar[i-1]*ar[k]*ar[j];
    Min=min(Min,temp);
  }
  dp[i][j]=Min;
  return dp[i][j];
}


void solve(){
  int n;
  cin>>n;
  vll ar(n);
  for(int i=0;i<n;i++){
    cin>>ar[i];
  }
  cout<<MCM(1,n-1,ar);
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
