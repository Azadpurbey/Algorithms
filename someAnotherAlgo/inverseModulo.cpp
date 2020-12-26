#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
vector<ll>fact(1000,1);
vector<ll>ifact(1000,1);
ll exp(ll x,ll n,ll m){
    ll res=1;
    while(n!=0){
        if(n%2!=0){
            res=(res*x)%m;
        }
        x=(x*x)%m;
        n/=2;
    }
    return res;
}

void inverseModulo(ll n,ll m){
    for(int i=1;i<=n;i++){
        fact[i]=(fact[i-1]*i)%m;
    }
    for(int i=1;i<=n;i++){
        ifact[i]=exp(fact[i],m-2,m);
    }
}
int main(){
    inverseModulo(n,m);
}