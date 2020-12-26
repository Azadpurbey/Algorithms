//Search in a row and col wise sorted matrix
#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int R=matrix.size();
    if(R==0)return false;   
    int C=matrix[0].size();
    int row=0,col=C-1;      // start from top right corner
    while(row<R && col>=0){
        if(matrix[row][col]==target)return true;
        if(matrix[row][col]>target)col--;
        else row++;
    }  
    return false;
}

int main(){
    int R,C,target;
    cin>>R>>C;
    cin>>target;
    vector<vector<int>>mat(R,vector<int>(C));
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++)cin>>mat[i][j];
    }
    cout<<searchMatrix(mat,target);
    return 0;
}