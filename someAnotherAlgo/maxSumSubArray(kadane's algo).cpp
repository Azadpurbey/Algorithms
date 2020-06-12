#include <bits/stdc++.h>
using namespace std;

int max_sum_array(int* ar,int n){
    int maxSum=0,maxSumTillNow=0;
    for(int i=0;i<n;i++){
        maxSumTillNow+=ar[i];
        if(maxSumTillNow<0)maxSumTillNow=0;
        if(maxSum<maxSumTillNow)maxSum=maxSumTillNow;
    }
return maxSum;
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
