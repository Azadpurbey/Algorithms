#include<bits/stdc++.h>  //Different ways of passing 2D array
using namespace std; 
#define f(i,a,b) for(int i=a;i<b;i++)
int Mat[100][100];
bool check(int row,int col,int n){
  for(int i=row-1;i>=0;i--){
    if(Mat[i][col]==1)return false;
  }
  for(int j=col-1,i=row-1;j>=0 && i>=0;j-- ,i--){
    if(Mat[i][j]==1)return false;
  }
  for(int j=col+1,i=row-1;j<n && i>=0;j++ ,i--){
    if(Mat[i][j]==1)return false;
  }
  return true;
}
void nQueenProblem(int row,int n){
  if(row==n){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cout<<Mat[i][j]<<" ";
      }
      cout<<endl;
    }
    cout<<"**********finish***********"<<endl;
    return;
  }
  for(int i=0;i<n;i++){
    if(check(row,i,n)){
      Mat[row][i]=1;
      nQueenProblem(row+1,n);
      Mat[row][i]=0;
    }
  }
  
}
int main(){
  freopen("input.txt","r",stdin);
  int n;
  cin>>n;
  nQueenProblem(0,n);
  return 0;
}  