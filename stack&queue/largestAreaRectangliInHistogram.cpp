#include<bits/stdc++.h>
using namespace std;
int largestRectangleArea(vector<int>&ar) {
    int n=ar.size();
    vector<int>right(n,n);
    vector<int>left(n,-1);
    stack<int>stk;
    for(int i=n-1;i>=0;i--){
        while(!stk.empty() && ar[stk.top()]>=ar[i]){
            stk.pop();
        }
        if(stk.empty())right[i]=n;
        else right[i]=stk.top();
        stk.push(i);
    }
    while(!stk.empty())stk.pop();
    for(int i=0;i<n;i++){
        while(!stk.empty() && ar[stk.top()]>=ar[i]){
            stk.pop();
        }
        if(stk.empty())left[i]=-1;
        else left[i]=stk.top();
        stk.push(i);
    }
    int Max=0;
    for(int i=0;i<n;i++){
        int a=(right[i]-left[i]-1)*ar[i];
        Max=max(Max,a);
    }
    return Max;
}
int main(){
    int n;
    vector<int>ar(n);
    for(int i=0;i<n;i++)cin>>ar[i];
    cout<<largestRectangleArea(ar);
    return 0;
}