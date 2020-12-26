#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  int MaxSquareSide(vector<vector<int>>& ar) {   // Max square in a binary matrix
    int R=ar.size(),Max=0;
    if(R==0)return 0;
    int C=ar[0].size();  
    for(int i=0;i<R;i++)Max=max(ar[i][0],Max);
    for(int i=0;i<C;i++)Max=max(ar[0][i],Max);
      
    for(int i=1;i<R;i++){
      for(int j=1;j<C;j++){
        if(ar[i][j]==1){
          ar[i][j]=min(ar[i-1][j-1],min(ar[i][j-1],ar[i-1][j]))+1;
        }
        Max=max(Max,ar[i][j]);
      }
    }
    return Max;
  }
};

int main(){
  freopen("input.txt","r",stdin);
  Solution ss;
  int R,C;
  cin>>R>>C;
  vector<vector<int>>ar(R,vector<int>(C));
  for(int i=0;i<R;i++)
    for(int j=0;j<C;j++)cin>>ar[i][j];
  cout<<ss.MaxSquareSide(ar); 
  return 0;
}
