#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<bool>prime(50000,true),ar(1000001,true),Data;
void create_prime(){
  prime[0]=prime[1]=false;
  for(ll i=2;i<300;i++){
    if(prime[i]){
      for(long long j=i;i*j<50000;j++)
        prime[i*j]=false;
    }
  }
  for(int i=0;i<50000;i++){
    if(prime[i]){
      Data.push_back(i);
    }
  }
}

int main(){
  create_prime();
  int t,lb,ub,a,start,end,hold;
  cin>>t;
  while(t--){
    cin>>lb>>ub; 
    for(int i=0;i<Data.size();i++){
      for(int j=Data[i];Data[i]*j<=ub;j++){
        a=Data[i]*j;
        if(a>=lb && a<=ub) ar[a-lb]=false;
      }
    }
    for(int i=0;i<ub-lb+1;i++){
      if(ar[i])cout<<i+lb<<endl;
    } 
  }
  return 0;
}

