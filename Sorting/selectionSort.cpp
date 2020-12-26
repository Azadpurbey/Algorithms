#include<bits/stdc++.h>
using namespace std;
void selection_sort(int ar[],int n){

	for (int i = 0; i <n-1; ++i)
	{   int min=ar[i],imin=i;
	    int j;
		for (j = i+1; j <n; ++j){
			if(min>ar[j]){
				min=ar[j];
				imin=j;
			}
		}
		int temp=ar[i];
		ar[i]=min;
		ar[imin]=temp;
	}
}

int main(){
 int n;
 cin>>n;
 int ar[n];
 for (int i = 0; i<n; ++i)
 	cin>>ar[i];
 selection_sort(ar,n);

 for (int i = 0; i <n; ++i){
 cout<<ar[i]<<" ";
 }
	return 0;
}
