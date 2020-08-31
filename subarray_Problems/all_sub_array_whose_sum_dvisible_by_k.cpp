 
#include<bits/stdc++.h>
using namespace std; 

int all_subarray_with_sum_divisible_by_k(vector<int>ar,int k){  
  int n=ar.size(),ans=0;              // all subarray with sum divisible by k
  for(int i=1;i<n;i++){
    ar[i]+=ar[i-1];
    if(ar[i]<0){
        ar[i]+=10000*k;
    }
    ar[i]%=k;
  }  
  unordered_map<int,int>mp;
  mp[0]=1;
  for(int i=0;i<n;i++){
    if(mp.find(ar[i])!=mp.end()){
      ans+=mp[ar[i]];
    }  
    mp[ar[i]]++;
  }
  return ans;
}


int main(){
  freopen("input.txt","r",stdin);
  int n,k;
  cin>>n>>k;
  vector<int> ar(n);
  for(int i=0;i<n;i++)cin>>ar[i];
  cout<<all_subarray_with_sum_divisible_by_k(ar,k);

  return 0;
}