#include<bits/stdc++.h>
using namespace std;
int lis(vector<int>&ar){
    int n=ar.size();
    vector<int>dp(n,1);
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(ar[j]<ar[i]) dp[i]=max(dp[i],dp[j]+1); 
        }
    }  
    return *max_element(dp.begin(),dp.end());  
}
int cuteLIS(vector<int>&ar){
    int n=ar.size();
    multiset<int>st;
    for(int i=0;i<n;i++){
        st.insert(ar[i]);
        auto it=st.find(ar[i]);
        it++;
        if(it!=st.end()){
            st.erase(it);
        }
    }
    return st.size();
}
int main(){  
    freopen("input.txt","r",stdin);
    int n;
    cin>>n;
    vector<int>ar(n);
    for(int i=0;i<n;i++)cin>>ar[i];
    cout<<cuteLIS(ar);
    return 0;  
}  
