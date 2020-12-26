#include<bits/stdc++.h>
using namespace std;
//const int n=9;
bool check(int row,int col,int x,int Mat[9][9]){
  for(int i=0;i<9;i++){
    if(Mat[i][col]==x)return false;
  }
  for(int i=0;i<9;i++){
    if(Mat[row][i]==x)return false;
  }
  int nRow=(row/3)*3,nCol=(col/3)*3;
  for(int i=nRow;i<nRow+3;i++){
    for(int j=nCol;j<nCol+3;j++){
      if(Mat[i][j]==x)return false;
    }
  }
  return true;
}
bool sudokuSolver(int Mat[9][9]){
    for(int i=0;i<9;i++){
    	for(int j=0;j<9;j++){
            if(Mat[i][j]==0){
                for(int k=1;k<=9;k++){
                    if(check(i,j,k,Mat)){
                        Mat[i][j]=k;
                        if(sudokuSolver(Mat))return true;
                        Mat[i][j]=0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main(){
    //int n=9;
    int Mat[9][9];
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)cin>>Mat[i][j];
    }
    cout<<"************solved************"<<endl;
    sudokuSolver(Mat);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)cout<<Mat[i][j]<<" ";
        cout<<endl;
    }
}

