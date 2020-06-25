//Find the median in only row  wise sorted matrix.(not col wise);
//R*C must be odd
#include<bits/stdc++.h>
using namespace std;

int Median(vector<vector<int>>& mat){
    int R=mat.size(),C=mat[0].size();;
    int Min=INT_MAX,Max=INT_MIN;
    for(int i=0;i<R;i++)Min=min(Min,mat[i][0]);
    for(int i=0;i<R;i++)Max=max(Max,mat[i][C-1]); 
    int req=(R*C +1)/2;
    while(Min<Max){
        int mid=(Min+Max)/2;
        int cont=0;
        for(int i=0;i<R;i++){
            cont+=upper_bound(mat[i].begin(),mat[i].end(),mid)-mat[i].begin();
        }
        if(cont<req)Min=mid+1;
        else Max=mid; 
    }
    return Min;   
}

int main(){
    int R,C;
    cin>>R>>C;
    vector<vector<int>>mat(R,vector<int>(C));
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++)cin>>mat[i][j];
    }
    cout<<Median(mat);
    return 0;
}