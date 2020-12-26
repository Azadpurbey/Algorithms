#include <bits/stdc++.h>  //BFS also work for disconnected graph
using namespace std;
int ar[1000][1000];
int check[1000];
int print_bfs(int start,int n){
 queue<int>q;
 q.push(start);
 check[start]=1;
 while(!q.empty()){
 	int a=q.front();
 	q.pop();
 	cout<<a<<" ";
 	for(int i=0;i<n;i++){
 		if(ar[a][i]==1 && check[i]==0){
 		   	q.push(i);
 			check[i]=1;  
 		}

 	}
 } 
 return 0;
}

void bfs(int n){
	for(int i=0;i<n;i++){
		if(check[i]==0)
			print_bfs(i,n);
	}
}

int main(){
int n,edge,head,tail;
cin>>n>>edge;
for(int i=0;i<edge;i++){
  cin>>tail>>head;
   ar[tail][head]=1;
   ar[head][tail]=1;
}
bfs(0,n);

    return 0;
}
