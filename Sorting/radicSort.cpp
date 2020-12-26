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
int digit(ll n,ll pass){
  for(int i=1;i<pass;i++)n/=10;
  return n%10;
}

void solve(){
  ll n;
  cin>>n;
  vll ar(n);
  f(i,0,n)cin>>ar[i];
  list<ll>hold[10];
  for(int pass=1;pass<=10;pass++){
    for(int i=0;i<n;i++){
      hold[digit(ar[i],pass)].pb(ar[i]);
    }
    int a=0;
    for(int i=0;i<10;i++){
      for(auto it:hold[i]){
        ar[a]=it;
        a++;
      }
      hold[i].clear();
    } 
  }
  print(ar);
  
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
