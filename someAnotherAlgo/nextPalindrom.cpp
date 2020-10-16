#include<bits/stdc++.h> \
#include<iostream>//spoj PALIN
using namespace std;
#define ll long long
#define For(a,b,c) for(int i=a;i<b;i+=c);
#define mod 1000007

bool check(vector<ll>ar,ll n,ll p,ll mid){
    ll init=0,final=mid,index=0;
    while(p>0){
      index=lower_bound(ar.begin()+index,ar.end(),final)-ar.begin();
      if(index>=n)return true;
      else{
        p--;
        if(ar[index]==final){
          init=ar[index];
          final=init+mid;
        } 
        else{
          init=ar[index-1];
          final=init+mid;
        }
      } 
    }
    return false;
}

int main(){
  ll n,p,low,high,ans;
  ci>>n>>p;
  vector<ll> ar(n);
  for(int i=0;i<n;i++)
     cin>>ar[i];
  for(int i=1;i<n;i++)
     ar[i]+=ar[i-1]; 
  low=1,high=ar[n];
  mid=(low+high)/2;
  while(low<=high){
    if(check(ar,n,p,mid)){
      ans=mid;
      high=mid-1;
    }
    else low=mid+1;
  }
 cout<<ans;
 
return 0;
}
 
