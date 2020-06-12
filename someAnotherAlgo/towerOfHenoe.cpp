#include<bits/stdc++.h>
using namespace std;
void TOH(int n,char beg,char aux,char End){
  if(n>=1){
   TOH(n-1,beg,End,aux);
   cout<<beg<<" "<<End<<endl;
   TOH(n-1,aux,beg,End);
  }
}
int main(){
  int n;
  char start='a',auxilary='b',target='c';

  cout<<"enter no. of rings";
  cin>>n;
  TOH(n,start,auxilary,target);
  return 0;
}
