 
#include<bits/stdc++.h>
using namespace std; 

int all_subarray_with_sum_zero(vector<int>ar,int k){  // all subarray with sum k
  int n=ar.size(),ans=0;
  for(int i=1;i<n;i++)ar[i]+=ar[i-1];
  unordered_map<int,int>mp;
  mp[0]=1;
  for(int i=0;i<n;i++){
    if(mp.find(ar[i]-k)!=mp.end()){
      ans+=mp[ar[i]-k];
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
  cout<<all_subarray_with_sum_zero(ar,k);

  return 0;
}