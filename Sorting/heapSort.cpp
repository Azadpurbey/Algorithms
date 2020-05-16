#include<bits/stdc++.h>
using namespace std;
#define mod 1000000
#define ll long long


void maxHeapify(int*ar,int n,int root){
  int largest=root,lc=2*root+1,rc=2*root+2;
  if(lc<n && ar[lc]>ar[largest])
    largest=lc;
  if(rc<n && ar[rc]>ar[largest])
    largest=rc; 
  if(largest!=root){
    swap(ar[root],ar[largest]);
    maxHeapify(ar,n,largest);
  }
}


void heapSort(int*ar,int n){
  for(int i=2*n-1;i>=0;i--)   //creation of max heap
    maxHeapify(ar,n,i);
  
  // cout<<"MaxHeap"<<endl;
 //    for(int i=0;i<n;i++)
 //        cout<<ar[i]<<" ";
 //    cout<<endl;
  for(int i=n-1;i>0;i--){
    swap(ar[0],ar[i]);
    maxHeapify(ar,i,0);
  }

}



int main(){
int n;
cin>>n;
int ar[n];
for(int i=0;i<n;i++)
  cin>>ar[i];
heapSort(ar,n);
for(int i=0;i<n;i++)
  cout<<ar[i]<<" ";
return 0;
}