#include <bits/stdc++.h>
using namespace std;
bool prime[50000],ar[1000001];
int data[50000];
void create_prime(){
for(int i=0;i<50000;i++)
  prime[i]=true;
  prime[0]=prime[1]=false;
  for(long long i=2;i<300;i++){
   if(prime[i]){
    for(long long j=i;i*j<50000;j++)
      prime[i*j]=false;
   }
  }
    int cont=0;
    for(int i=0;i<50000;i++){
        if(prime[i]){
          data[cont]=i;
            cont++;
        }
    }
    data[cont]=-1;
}

int main(){
 create_prime();
int t,lb,ub,a,start,end,hold;
cin>>t;
while(t--){
  cin>>lb>>ub;
    for(int i=0;i<ub-lb+1;i++)
        ar[i]=true;
 /*   
for(int i=0;i<50000;i++)
    if(data[i]>=hold){
      end=i+1;
      break;  
    } */
  
    
    
 for(int i=0;data[i]!=-1;i++)
   for(int j=data[i];data[i]*j<=ub;j++){
       a=data[i]*j;
       if(a>=lb && a<=ub)
           ar[a-lb]=false;
   }
 for(int i=0;i<ub-lb+1;i++)
    if(ar[i])
    cout<<i+lb<<endl;
}
    return 0;

}

