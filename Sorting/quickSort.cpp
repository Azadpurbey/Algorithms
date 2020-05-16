#include<bits/stdc++.h>
using namespace std;
void swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}

int partation(int*ar,int n){
	int pivot=n-1,p_index=0;
	for(int i=0;i<n-1;i++){
      if(ar[i]<=ar[pivot]){
      	swap(ar[i],ar[p_index]);
      	p_index++;
      }
	}
	swap(ar[p_index],ar[pivot]);
	return p_index;
}

void quickSort(int*ar,int n){
	if(n<=1)return;
	int p=partation(ar,n);
	quickSort(ar,p);
	quickSort(ar+p+1,n-p-1);
}

int main(){
	int n;
	cin>>n;
	int ar[n];
	for(int i=0;i<n;i++)
		cin>>ar[i];
	quickSort(ar,n);
	for(int i=0;i<n;i++)
		cout<<ar[i]<<" ";

	return 0;
}
