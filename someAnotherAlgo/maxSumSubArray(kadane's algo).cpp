#include <bits/stdc++.h>
using namespace std;
//this is a way to comment anything
int max_sum_array(int* ar,int n){
  int Max=0,cur=0;
  for(int i=0;i<n;i++){
    cur+=ar[i];
    if(cur<0)cur=0;
    if(Max<cur)Max=cur;
  }
  return Max;
}

int main(){
int n;
cin>>n;
int ar[n];
for (int i = 0; i < n; ++i)
   cin>>ar[i];
int ans1=max_sum_array(ar,n);
cout<<"ans= "<<ans1;
  return 0;
}
