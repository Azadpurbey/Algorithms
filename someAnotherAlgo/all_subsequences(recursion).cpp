#include<bits/stdc++.h>      //print all subsequences of a given string
using namespace std;
int subsequence(string s,string output[]){
  if(s[0]=='\0'){
    output[0]="";
    return 1;
  }
  else{
      
  int cont=subsequence(s.substr(1),output);
    for(int i=0;i<cont;i++){
      output[cont+i]=s[0]+output[i];
    }
    return 2*cont;
  }
}

int main() {
string s,output[1000];
cin>>s;
int l=subsequence(s,output);
for(int i=0;i<l;i++)
  cout<<output[i]<<endl;;

return 0;
}