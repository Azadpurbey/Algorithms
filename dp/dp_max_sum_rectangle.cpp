#include<iostream>
using namespace std;
int max_sum[100][100][100][100];
int main(){
 int r,c,max=0,x,y,z;
 cin>>r>>c;
 int ar[r][c],sum[r+2][c+2];
 for(int i=0;i<r;i++)
   for(int j=0;j<c;j++)
      cin>>ar[i][j];
  sum[r-1][c-1]=ar[r-1][c-1];
 for(int i=r-2;i>=0;i--)
   sum[i][c-1]=ar[i][c-1]+sum[i+1][c-1];

 for(int i=c-2;i>=0;i--)
   sum[r-1][i]=ar[r-1][i]+sum[r-1][i+1];

  for(int i=r-2;i>=0;i--){
     for(int j=c-2;j>=0;j--){
        int hold=0;
        for(int k=i;k<r;k++){
          hold+=ar[k][j];
        }
      sum[i][j]=hold+sum[i][j+1];
     }
  }
  for(int i=0;i<=r;i++){
    sum[i][c]=0;
    sum[i][c+1]=0;
  }

  for(int i=0;i<=c;i++){
    sum[r][i]=0;
    sum[r+1][i]=0;
  }

   for(int r1=0;r1<r;r1++)
     for(int c1=0;c1<c;c1++)
      for(int r2=r1+1;r2<=r;r2++)
        for(int c2=c1+1;c2<=c;c2++){
              x=sum[r1][c2+1];
               y=sum[r2+1][c1];
               z=sum[r2+1][c2+1];

         max_sum[r1][r2][c1][c2]=sum[r1][c1]-x-y+z;
        }


     for(int r1=0;r1<r;r1++)
      for(int c1=0;c1<=c;c1++)
        for(int r2=r1+1;r2<r;r2++)
        for(int c2=c1+1;c2<=c;c2++)
            if(max<max_sum[r1][r2][c1][c2])
                max=max_sum[r1][r2][c1][c2];

        cout<<max;

    return 0;
}
