#include <bits/stdc++.h>
using namespace std;
int power(int a,string s,int m){
  long long x,y,z,l,ans=1,hold;
  x=1,y=a,z=(y*y)%m;
  l=s.length();
  for(int i=l-1;i>=0;i--){
    if(s[i]=='0')hold=x;
    else if(s[i]=='1')hold=y;
    else hold=z;
    ans=(ans*hold)%m;
    y=(y*y*y)%m;
    z=(y*y)%m;
  }
  return ans;
}

int main(){
int a,m,t;
string s;
cin>>t;
while(t--){
 cin>>a>>s>>m;
 cout<<power(a,s,m)<<endl; 
}

  return 0;
}

