#include <bits/stdc++.h>
using namespace std;
#define mod 10000007 
int power(long long x,long long n){
  if(x==0)return 0;
  if(n==0)return 1;
  long long a=x*x;
   if(n%2==0) return power(a,n/2)%mod;
    return (x*power(a,n/2)  )%mod; 
}

int power_iteratively(long long x,long long n){
  long long res=1;
  if(x==0)return 0;
  if(n==0)return 1;
  while(n>1){
    if(n%2==1)
     res=(res*x)%mod;
    x=(x*x)%mod; 
    n/=2;
  }
  return (res*x)%mod;
}




int main(){
int x,n;
cin>>x>>n;
cout<<power(x,n)<<endl;
cout<<endl<<power_itteratively(x,n);

  return 0;
}
