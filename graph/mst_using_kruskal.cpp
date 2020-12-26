#include<bits/stdc++.h>
using namespace std;
bool cmp(vector<int>x,vector<int>y){
    return x[2]<=y[2];
}
int get_parent(int x,vector<int>&parent){
    if(parent[x]==x)return x;
    parent[x]=parent[parent[x]];
    return get_parent(parent[x],parent);
}
vector<vector<int>>mst_kruskal(int V,vector<vector<int>>&edges,vector<int>&parent){
  vector<vector<int>>ans;
  int cont=0,a=0;
  while(cont!=V-1){
    int src_parent=get_parent(edges[a][0],parent);
    int dest_parent=get_parent(edges[a][1],parent);
    if(src_parent!=dest_parent){
      ans.push_back(edges[a]);
      cont++;
      parent[src_parent]=dest_parent;
    }
    a++;
    if(a==edges.size() && cont!=V-1){  // extra for safty( it mst don't exist)
      cout<<"something is wrong";
      break;
    }
  }
  return ans;
}
int main(){
  freopen("input.txt","r",stdin);
  int E,V,a,b,wt;
  cin>>V>>E;
  vector<vector<int>>edges;
  for(int i=0;i<E;i++){
    cin>>a>>b>>wt;
    edges.push_back({a,b,wt});
  }
  sort(edges.begin(),edges.end(),cmp);
  vector<int>parent(V+1);
  for(int i=1;i<=V;i++)parent[i]=i;
  vector<vector<int>>ans=mst_kruskal(V,edges,parent);
  for(auto it:ans){
    cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
  }
  return 0;
}