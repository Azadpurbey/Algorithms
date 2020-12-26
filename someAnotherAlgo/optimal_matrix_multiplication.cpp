#include<bits/stdc++.h>
using namespace std;

void printMatrix(int*s ,int i,int j,int n,char &a){
	if(i==j){
		cout<<a++;
		return;
	}
	cout<<"(";
	printMatrix(s,i,*(s+i*n +j),n,a);
	printMatrix(s,*(s+i*n+j)+1,j,n,a);
	cout<<")";
}




int main(){
int ar[]={30,35,15,5,10,20,25};
int n=7;

int bracket[n][n],m[n][n];
for(int i=0;i<n;i++)m[i][i]=0;

for(int L=2;L<n;L++){
	for(int i=1;i<n-L+1;i++){
		int j=i+L-1;
		m[i][j]=INT_MAX;
		for(int k=i;k<j;k++){
			int q=m[i][k]+m[k+1][j]+ar[i-1]*ar[j]*ar[k];
			if(q<m[i][j]){
				m[i][j]=q;
				bracket[i][j]=k;
			}
		}
	} 
}
cout<<"order is "<<m[1][n-1]<<endl;
char name='A';
printMatrix((int*)bracket,1,n-1,n,name);
return 0;
}