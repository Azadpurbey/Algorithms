#include<iostream>
using namespace std;
int main(){
int v;
cin>>v;
int g[v][v],n,i,j,k;
cout<<"Enter adjacency matrix \n";
for(i=0;i<v;i++)
 for(j=0;j<v;j++)
   cin>>g[i][j];

for(k=0;k<v;k++){
  for(i=0;i<v;i++){
     if (g[i][k]>0){
        for(j=0;j<n;j++){
           if(g[k][j]>0 && g[i][j]>(g[i][k]+g[k][j]))
                 g[i][j]=g[i][k]+g[k][j];   
        }
     }
   }
}
cout<<"\nOutput : \n";
for(i=0;i<v;i++){
   for(j=0;j<v;j++)
      cout<<g[i][j]<<" ";
    cout<<"\n";
 }
 return 0;
}