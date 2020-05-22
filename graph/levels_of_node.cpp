#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000
vector<int> BFS(vector<vector<int>>& friends,int id, int level){
  queue<int>qq;
  vector<int>ss;
  qq.push(id);  
  visited[id]=1;
  while(!qq.empty()){
     int cur=qq.front();
     qq.pop();
     for(int i=0;i<friends[cur].size();i++){
      int hold=friends[cur][i];
      if(visited[hold]==0){
          if(level==1)ss.push_back(hold);
           qq.push(hold);
            visited[hold]=1;
      }
     }
     level--;
     if(level==0)break;
  }
  for(auto it:ss)cout<<it<<" ";
  return ss;
  
}


int main(){
  int v,e,a,b;
  cin>>v>>e;
  vector<vector<int>>ar[v+1];
  for(int i=1;i<=e;i++){
   cin>>a>>b;
   ar[a].push_back(b);
   ar[b].push_back(b);
  }
}