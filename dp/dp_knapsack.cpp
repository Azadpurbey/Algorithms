#include<bits/stdc++.h>
using namespace std;

int knapsack(int* w, int* v, int n, int maxWeight){
int **dp=new int*[n+1];
    for(int i=0;i<=n;i++)
        dp[i]=new int[maxWeight+1];
 for(int i=0;i<=n;i++)
  dp[i][0]=0;
 for(int i=0;i<=maxWeight;i++)
  dp[0][i]=0;

 for(int i=1;i<=n;i++)
   for(int j=1;j<=maxWeight;j++){
   	int x=j-w[i-1];
   	if(x<0)
   		dp[i][j]=dp[i-1][j];
   	else
   		dp[i][j]=max(v[i-1]+dp[i-1][x],dp[i-1][j]);
   }

 return dp[n][maxWeight];

}


int main(){
int n;
cin>>n;
int wt[n],v[n];
for(int i=0;i<n;i++)
 cin>>wt[i];
for(int i=0;i<n;i++)
 cin>>v[i];
int maxWeight;
cin>>maxWeight;
cout<<knapsack(wt,v,n,maxWeight);


}

/* recursive solution
int dp[10001][101];
int knapsack(int* wt, int* v, int n, int maxWeight){
if(dp[n][maxWeight]!=0)return dp[n][maxWeight];    
if(n==0)return 0;
if(maxWeight==0)return 0;
int y=knapsack(wt+1,v+1,n-1,maxWeight);
if(maxWeight-wt[0]<0){
    dp[n][maxWeight]=y;
    return dp[n][maxWeight];
}
int x=v[0]+knapsack(wt+1,v+1,n-1,maxWeight-wt[0]);
dp[n][maxWeight]=max(x,y);
return dp[n][maxWeight];
} */
