#include<bits/stdc++.h>
using namespace std;

void Merge(int* ar,int lb,int ub){
	int a=0,b=0;
	int mid=(lb+ub)/2;
	int n1=(mid-lb+1);
	int n2=ub-mid;
	int ar1[n1+1],ar2[n2+1];
	ar1[n1]=ar2[n2]=INT_MAX;
	for(int i=lb;i<=mid;i++){
         ar1[a]=ar[i];
         a++;
	}
    for(int i=mid+1;i<=ub;i++){
         ar2[b]=ar[i];
         b++;
	}
	a=b=0;

	for(int i=lb;i<=ub;i++){
		if(ar1[a]<ar2[b]){
			ar[i]=ar1[a];
			a++;
		}
		else{
			ar[i]=ar2[b];
			b++;
		}
	}
}


void mergeSort(int* ar,int lb,int ub){
    if(lb>=ub)return;
	int mid=(lb+ub)/2;
	mergeSort(ar,lb,mid);
	mergeSort(ar,mid+1,ub);
	Merge(ar,lb,ub);

}

int main(){
	int n;
	cin>>n;
	int ar[n];
	for(int i=0;i<n;i++)
		cin>>ar[i];
	mergeSort(ar,0,n-1);
	for(int i=0;i<n;i++)
		cout<<ar[i]<<" ";

	return 0;
}
