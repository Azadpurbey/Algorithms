#include<bits/stdc++.h>
using namespace std;

 int gcd_euclid_method(int a,int b){
    if(b==0)return a;
   return gcd_euclid_method(b,a%b);
  }
int main(){
 int a,b;
 cin>>a>>b;
 cout<<gcd_euclid_method(a,b);
 return 0;
}
