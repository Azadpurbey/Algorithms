#include<bits/stdc++.h>
using namespace std;
int countWaysToMakeChange(int d[], int n, int value){
int data[n+1][value+1];
  for(int j=1;j<=value;j++)
    data[0][j]=0;
  for(int i=0;i<=n;i++)
    data[i][0]=1;

int value1=value;
 for(int nc=1;nc<=n;nc++)
   for(int v=1;v<=value1;v++){
    value=v-d[n-nc];
     if(value>-1)
    data[nc][v]=data[nc][value] + data[nc-1][v];
    else  data[nc][v]= 0 + data[nc-1][v];
   }
 return data[n][value1];

}

int main(){



}
