#ifndef AZAD    //conversion of sorted array into balanced BST
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
  #define InputOutput freopen("input.txt","r",stdin);//freopen("output.txt","w",stdout);
 using namespace std;
#endif
void helper(vll &ar,vll &ans,ll lb,ll ub){
  if(lb>ub)return;
  ll mid=(lb+ub)/2;
  ans.pb(ar[mid]);
  helper(ar,ans,lb,mid-1);
  helper(ar,ans,mid+1,ub);
}
void solve(){
  ll n;
  cin>>n;
  vll ans,ar(n);
  f(i,0,n)cin>>ar[i];
  helper(ar,ans,0,n-1);
  cout<<ans.size()<<endl;
  print(ans);
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