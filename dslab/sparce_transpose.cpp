#include<bits/stdc++.h>
using namespace std;
struct sparceElement{
  int r,c,v;
};
bool method(sparceElement a, sparceElement b){
 if(a.r==b.r)   return a.c<b.c;
 return a.r<b.r;
}
void swap(int *a ,int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}

int main() {
  int n;
  cout<<"no. of element in matrix";
  cin>>n;
 sparceElement ar[n];
  for(int i=0;i<n;i++)
    cin>>ar[i].r>>ar[i].c>>ar[i].v;

  for(int i=0;i<n;i++)
   swap(ar[i].r,ar[i].c);

   sort(ar,ar+n,method);
   cout<<endl;
   for(int i=0;i<n;i++)
    cout<<ar[i].r<<" "<<ar[i].c<<" "<<ar[i].v<<endl;

   return 0;
}
