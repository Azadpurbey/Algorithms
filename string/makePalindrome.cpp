#include<bits/stdc++.h> // Min character req to add in starting to make it a palindrom 
using namespace std;

int minChar(string A) {
  string B=A;
  reverse(B.begin(),B.end());
  string S=A+"#"+B;
  int n=S.length();
  int i=1,j=0;
  vector<int>lps(n,0);
  while(i<n){
    if(S[i]==S[j]){
      lps[i]=j+1;
      i++;j++;
    }
    else{
      if(j==0)i++;
      else{
        j=lps[j-1];
      }
    }
  }
  int ans=A.length()-lps[n-1];
  return ans;
}

int main(){
  string s;
  cin>>s;
  cout<<minChar(s);
  return 0;
}