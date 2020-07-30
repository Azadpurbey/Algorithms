#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>fact(80,1);
void factorial(){
    for(ll i=2;i<=20;i++){
        fact[i]=fact[i-1]*i;
    }    
}
string helper(vector<int>ar,int n){
    if(ar.size()==0)return "";
    ll f=fact[ar.size()-1];
    if(ar.size()>21)f=INT_MAX;
    int pos=n/f;
    n%=f;
    
    string ch=to_string(ar[pos]);
    ar.erase(ar.begin()+pos);
    return ch+helper(ar,n);
    
}
string getPermutation(int n, int B){
    factorial();
    vector<int>ar(n);
    for(int i=0;i<n;i++)ar[i]=i+1;
    return helper(ar,B-1);  // indexing start from zero so B-1
}
int main(){    // n=number of elements(1,2,3,4,...n)    Bth permutation
    int n,B;
    cin>>n>>B;
    cout<<getPermutation(n,B);
}