#include<bits/stdc++.h>
using namespace std;
void BinearyPermutation(int v[],int i,int l){
if(i>l){
 for(int a=0;a<=l;a++)
  cout<<v[a];
  cout<<endl;
}
else{
        v[i]=0;
        BinearyPermutation(&v[0],i+1,l);
        v[i]=1;
        BinearyPermutation(&v[0],i+1,l);
}

}
int main(){
 int n;
 cin>>n;
 vector<int> v(n,0);
 BinearyPermutation(&v[0],0,n-1);
  return 0;
}
