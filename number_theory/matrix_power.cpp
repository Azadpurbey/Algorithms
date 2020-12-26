#include <bits/stdc++.h>
using namespace std;

void multiply(int a[2][2],int b[2][2]){
  int ans[2][2];
  long long sum=0;

    for(int i=0;i<2;i++)
    for(int j=0;j<2;j++){
      sum=0;
      for(int k=0;k<2;k++)
               sum=(sum+((long long)a[i][k]*b[k][j])%mod)%mod;
            ans[i][j]=sum;
    }
    for(int i=0;i<2;i++)
    for(int j=0;j<2;j++)
      a[i][j]=ans[i][j];
  return;
}

void matrix_power(int a[2][2],int n){
 if(n==0 || n==1)return;
 int res[2][2]={{1,0},{0,1}};
 while(n>1){
  if(n%2==1)
    multiply(res,a);
  multiply(a,a);
  n/=2;
 }
 multiply(a,res);
}


int fibonachi(int n){
 int A[2][2]={{1,1},{1,0}};
 power(A,n-1);
 return A[0][0];
}

int main(){
int n;
cin>>n;
cout<<fibonachi(n);
return 0;
}

