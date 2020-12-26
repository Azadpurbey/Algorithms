#include<bits/stdc++.h>
using namespace std;
void swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}
void bubbleSort(int ar[],int n){
	int flag=0;
	for (int pass =1; pass <n; ++pass){
		int flag=0;
		for (int j = 0; j < n-pass; ++j){
			if(ar[j]>ar[j+1]){
			 swap(ar[j],ar[j+1]);
				flag=1;
			}
		}
		if(flag==0)break;             //SOME ADVANCEMENT IN BUBBLE SORT
	    flag=0;
	}
}
int main(){
 int n;
 cin>>n;
 int ar[n];
 for (int i = 0; i<n; ++i)
 	cin>>ar[i];
 bubbleSort(ar,n);
 for (int i = 0; i <n; ++i)       //display
    cout<<ar[i]<<" ";
	return 0;
}
