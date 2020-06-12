#include<bits/stdc++.h>
using namespace std;
void permutation(char *s,int i,int n){
  if(i==n){
    cout<<s<<endl;
    return;
  }
  for(int j=i;j<=n;j++){
    swap(s[i],s[j]);
    permutation(s,i+1,n);
    swap(s[i],s[j]);
  }
}

int main(){
string s;
cin>>s;
int l=s.length();
permutation(&s[0],0,l-1);
return 0;
}
