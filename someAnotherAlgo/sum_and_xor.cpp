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
  #define all(v) v.begin(),v.end()
  #define allr(v) v.rbegin(),v.rend()
  #define p4(x,y,z,w) cout<<"x="<<x<<" y="<<y<<" z="<<z<<" w="<<w<<endl
  #define p3(x,y,z) cout<<"x="<<x<<" y="<<y<<" z="<<z<<endl
  #define p2(x,y) cout<<"x="<<x<<" y="<<y<<endl
  #define p1(x) cout<<"x="<<x<<endl
  #define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  #define InputOutput freopen("input.txt","r",stdin);//freopen("output.txt","w",stdout);
  const int mod = 1000000007;//10^9+7
  const ll INF=9000000000000000000;  // 9*10^18
 using namespace std; 
#endif
void solve(){
  ll u,v;    // u=xor v=sum
  cin>>u>>v;
  if(u>v || u%2!=v%2){   // xor is greater or parrity diffeent 
    cout<<-1<<endl;      // no solution
    return;
  }  
  if(u==v){                      // both are equal
    if(u==0)cout<<0<<endl;         // equal to  zero
    else cout<<1<<endl<<u<<endl;    // equal to non zero
    return;
  }
  ll x=(v-u)/2;
  if((x&u)==0){               // can be divided into two element
    cout<<2<<endl;
    cout<<x+u<<" "<<x<<endl;
  }
  else{
    cout<<3<<endl;            // except above always divided into three element
    cout<<u<<" "<<x<<" "<<x<<endl;  // [u,x,x] xor=u
  }                                 // sum=2*x +u => x=(u-sum)/2 and here sum=v
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