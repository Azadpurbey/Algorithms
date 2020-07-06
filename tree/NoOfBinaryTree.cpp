#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll binarySearchTree(int n){
    if(n<=2)return n;
    ll ar[n+1];
    ar[0]=1,ar[1]=1,ar[2]=2;
    for(int i=3;i<=n;i++){
        ll sum=0;
        for(int j=0;j<i;j++){
            sum+=ar[j]*ar[i-1-j];
        }
        ar[i]=sum;
    }
    return ar[n];
}
ll binaryTree(int n){
    ll ans=binarySearchTree(n);
    ll a=1;
    for(int i=2;i<=n;i++)a*=i;  // binarySearchTree*(n!);
    return ans*a;
}

int main(){
    int n;
    cin>>n;
    cout<<"No of binarySearch Tree"<<binarySearchTree(n)<<endl;
    cout<<"No of binaryTree"<<binaryTree(n);

    return 0;
}