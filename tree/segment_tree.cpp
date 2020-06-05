#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define pb push_back
using namespace std;

  void buildTree(int *ar,int *tree,int start,int end,int treeNode){
    if(start==end){
      tree[treeNode]=ar[start];
      return;
    }  
    int mid=(start+end)/2;
    buildTree(ar,tree,start,mid,2*treeNode);
    buildTree(ar,tree,mid+1,end,2*treeNode+1);
    tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];
  }

  void updateTree(int *tree,int start,int end,int treeNode,int index,int val){
    if(start==end){
      tree[treeNode]=val;
      return;
    }
    int mid=(start+end)/2;
    if(index>mid)updateTree(tree,mid+1,end,2*treeNode+1,index,val);
    else updateTree(tree,start,mid,2*treeNode,index,val);
    tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];
  }

  int query(int *tree,int start,int end,int treeNode,int lb,int ub){
    if(start>ub || end<lb)return 0;  // completely outside
    if(start>=lb && end<=ub)return tree[treeNode]; // comletely inside
    
    int mid=(start+end)/2;
    int a=query(tree,start,mid,2*treeNode,lb,ub);
    int b=query(tree,mid+1,end,2*treeNode+1,lb,ub);
    return a+b;
  }
int main(){
  freopen("input.txt","r",stdin);
  int n,index,val,start,end;
  cin>>n;
  int ar[n],tree[4*n]={0};
  for(int i=0;i<n;i++)cin>>ar[i];

  buildTree(ar,tree,0,n-1,1);
  for(int i=1;i<4*n;i++)cout<<tree[i]<<" ";
  cout<<endl;
  cin>>index>>val;
  ar[index]=val;
  updateTree(tree,0,n-1,1,index,val);
  for(int i=1;i<4*n;i++)cout<<tree[i]<<" ";

  cin>>start>>end;
  cout<<endl<<query(tree,0,n-1,1,start,end);
  
  return 0; 
}