#include<bits/stdc++.h>  //************Different ways of passing 2D array**************
using namespace std; 
#define f(i,a,b) for(int i=a;i<b;i++)

const int Max=1000;
void display(int ar[][Max],int a,int b){
  f(i,0,a){
    f(j,0,b){
      cout<<ar[i][j]<<" ";
    }
    cout<<endl;
  }
}
void display(int **ar,int a,int b){
  f(i,0,a){
    f(j,0,b){
      cout<<ar[i][j]<<" ";
    }
    cout<<endl;
  }
}
void display(vector<vector<int>> ar,int a,int b){
  f(i,0,a){
    f(j,0,b){
      cout<<ar[i][j]<<" ";
    }
    cout<<endl;
  }
}


int main(){
  //freopen("input.txt","r",stdin);
  int a,b;
  cin>>a>>b;
  int ar1[Max][Max];

  int **ar2=new int*[a];
  for(int i=0;i<a;i++){
    ar2[i]=new int[b];
  }

  vector<vector<int>>ar3(a,vector<int>(b));
  
  f(i,0,a){
    f(j,0,b){
      cin>>ar1[i][j];
      ar2[i][j]=ar3[i][j]=ar1[i][j];
    } 
  }
  
  display(ar1,a,b);
  display(ar2,a,b);
  display(ar3,a,b);

  return 0;
}  
