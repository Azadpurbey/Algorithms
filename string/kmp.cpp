#include <bits/stdc++.h>
using namespace std;
bool kmpAlgo(string s1,string s2){
  int n=s1.length();
  string s=s1+"#"+s2;
  int l=s.length();
  vector<int>ans(l,0);
  int j=0,i=1;
  while(i<l){
    if(s[i]==s[j]){
      ans[i]=j+1;
      if(ans[i]==n)return true;
      j++;i++;
    }  
    else{
      if(j==0){
        ans[i]=0;
        i++;
      }
      else   j=ans[j-1];
    }
  }
return false;
}

int main(){
  string s1,s2;
  cin>>s1>>s2;
  cout<<kmpAlgo(s1,s2);
  return 0;
} 