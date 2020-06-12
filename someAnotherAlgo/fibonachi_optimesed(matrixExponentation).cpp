#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
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

int fibo(int n){
	int a[2][2]={0,1,1,1};
	matrix_power(a,n);
	return a[0][1];
}


int main(){
int a,b,t;
cin>>t;
while(t--){
 cin>>a>>b;
 cout<<(fibo(b+2)-fibo(a+1) +mod)%mod<<endl;

}
return 0;
}
