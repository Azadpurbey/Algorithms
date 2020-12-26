#include<bits/stdc++.h>
using namespace std;

int main() {
  int n,m,flag=0;
  cout<<"no. of element in 1st matrix";
  cin>>n;
 cout<<"enter row no, column no, and va1ue\n";
  vector< vector<int> >v1,v2,v3;
  for(int i=0;i<n;i++){
    int a,b,c;
    cin>>a>>b>>c;
    v1.push_back({a,b,c});
  }
  cout<<"no. of element in 2nd matrix";
  cin>>m;
  cout<<"enter row no, column no, and va1ue\n";
  for(int i=0;i<m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    v2.push_back({a,b,c});
  }
 for(int i=0;i<n;i++){
  flag=0;
  for(int j=0;i<m;j++){
    if(v1[i][0]==v1[j][0] &&v1[i][1]==v1[j][1]){
       v1[i][2]+=v2[j][2];
       v3.push_back(v1[i]);
       v2[j][0]=-1;
       flag=1;
    }
    break;
  }
   if(flag==0)
    v3.push_back(v1[i]);

 }

 for(int i=0;i<m;i++ ){
   if(v2[i][0]!=-1)
   v3.push_back(v2[i]);
 }
int s=v3.size();
cout<<endl;
  for(int i=0;i<s;i++)
    cout<<v3[i][0]<<" "<<v3[i][1]<<" "<<v3[i][2]<<endl;

   return 0;
}

