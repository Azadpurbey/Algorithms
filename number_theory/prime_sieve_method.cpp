#include <bits/stdc++.h>
using namespace std;
vector<bool> prime(100000000,true);
void create_prime(){
  prime[0]=prime[1]=false;
  for(int i=2;i*i<100000000;i++){
    if(prime[i]){
      for(int j=i;i*j<100000000;j++)
        prime[i*j]=false;
    }
  }
}

int main(){
  create_prime();
  for(int i=0;i<10000;i++)
    if(prime[i])cout<<i<<" ";
    
  return 0;
}