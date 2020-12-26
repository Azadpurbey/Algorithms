#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 10000007 
int power(ll x,ll n){
  if(x==0)return 0;
  if(n==0)return 1;
  ll a=x*x;
   if(n%2==0) return power(a,n/2)%mod;
    return x*power(a,n/2)%mod; 
}

int exp(ll x,ll n){
  ll res=1;
  while(n!=0){
    if(n%2!=0)res=res*x%mod;
    x=x*x%mod; 
    n/=2;
  }
  return res%mod;
}




int main(){
int x,n;
cin>>x>>n;
cout<<power(x,n)<<endl;
cout<<endl<<exp(x,n);

  return 0;
}
