#include<iostream>
#define ll long long
using namespace std;
ll ar[70];
ll staircase(int n){
 if(n==0|| n==1) return 1;
 if(n==2) return 2;
 if(ar[n]!=0)return ar[n];   
  long hold =staircase(n-1)+staircase(n-2)+staircase(n-3);
    ar[n]=hold;
    return ar[n];
     
}

int main(){
	int n;
	cin>>n;
	cout<<staircase(n);
	return 0;
}