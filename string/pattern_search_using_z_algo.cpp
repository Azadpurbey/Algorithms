#include <bits/stdc++.h>
using namespace std;

int* z_algo(string s){
  int l=s.length(),left,right,hold,i=1,j,start=0;
  int* ar=new int[l];
  ar[0]=0;
  while(i<l){
    left=right=i;
    start=0;
    while(s[right]==s[start]){
      right++;
      start++;
    }
    if(start!=0) ar[i]=start;
    else ar[i]=0;

    hold=1;
    for(j=left+1;j<right;j++){
      if(j+ar[hold]>=right) break;
      else{
      ar[j]=ar[hold];
      hold++;
      }
    }
    i=j;
  }
 return ar;
}

int* pattern_search(string s,string k){
  string str=k+'$'+s;
  int* data=z_algo(str);
  return data;
}



int main(){
  string text,pattern;
  cin>>text>>pattern;
    int *z=pattern_search(text,pattern);
    int l=pattern.length();
   for(int i=0;i<text.length();i++)
    cout<<z[i]<<" ";
   cout<<endl;
  for(int i=0;i<=text.length()+l;i++){
    if(z[i]==l)
    cout<<i-l-1<<" ";
  }
  return 0;
}

