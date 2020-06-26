#define F first   // Find first min element in forward direction in o(n)
#define S second
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> ar(n),post(n,-1);
    for(int i=0;i<n;i++)cin>>ar[i];
    stack<pair<int,int>>st;
    st.push({INT_MIN,-1});
    for(int i=0;i<n;i++){
        pair<int,int>cur=st.top();
        if(ar[i]>=cur.F)st.push({ar[i],i});
        else{
            while(ar[i]<cur.F){
                post[cur.S]=i;
                st.pop();
                cur=st.top();
            }
            st.push({ar[i],i});
        }
    }
    for(auto it:post)cout<<it<<" ";
    return 0;
}