#include<bits/stdc++.h>
using namespace std;
void insertionSort(int ar[],int n){
  for (int i = 1; i <n; ++i){
    int key =ar[i],j=i-1;
    while(ar[j]>key && j>=0){
      ar[j+1]=ar[j];
      j--;
    }
    ar[j+1]=key;
  }
}

int main(){
 int n;
 cin>>n;
 int ar[n];
 for (int i = 0; i<n; ++i)
  cin>>ar[i];
 insertionSort(ar,n);
 for (int i = 0; i <n; ++i)       //display
    cout<<ar[i]<<" ";
  return 0;
}
