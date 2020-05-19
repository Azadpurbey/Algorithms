#include <bits/stdc++.h>
using namespace std;
vector<int>v;
bool prime[100000000];
void create_prime(){
for(int i=0;i<100000000;i++)
  prime[i]=true;
  prime[0]=prime[1]=false;
  for(int i=2;i*i<100000000;i++){
   if(prime[i]){
    for(int j=i;i*j<100000000;j++)
      prime[i*j]=false;
   }
  }
   if(prime[i])v.push_back(i);
}

int main(){
create_prime();
cout<<v.size()<<endl;
for(int i=0;i<10000;i++)
	cout<<v[i]<<" ";
  return 0;
}

