#include<bits/stdc++.h>  //print all possible path in a maze from (0,0) to (R-1,C-1)
using namespace std;     //0 in the Maze means water/no path or 1 means path possible
#define f(i,a,b) for(int i=a;i<b;i++)
int Mat[100][100],path[100][100];
void findPath(int row,int col,int R,int C){
  if(row==R-1 && col==C-1){
    for(int i=0;i<R;i++){
      for(int j=0;j<C;j++){
        cout<<path[i][j]<<" ";
      }
      cout<<endl;
    }
    cout<<"**********finish***********"<<endl;
    return;
  }
  if(row>=R || col>=C || row<0 || col<0|| path[row][col]==1 || Mat[row][col]==0)return;
  path[row][col]=1;
  findPath(row+1,col,R,C);
  findPath(row-1,col,R,C);
  findPath(row,col+1,R,C);
  findPath(row,col-1,R,C);
  path[row][col]=0;
  
}
int main(){
  freopen("input.txt","r",stdin);
  int R,C;
  cin>>R>>C;
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++)cin>>Mat[i][j];
  }
  path[R-1][C-1]=1;
  findPath(0,0,R,C);
  return 0;
}