#include<bits/stdc++.h>
using namespace std;

double helper(const vector<int> &nums1, const vector<int> &nums2){
    int n1=nums1.size(),n2=nums2.size();
    if(n1==0 && n2==0)return 0;
    if(n2==0){
        if(n1%2==0)return ((double)nums1[n1/2]+nums1[(n1-1)/2])/2;
        return nums1[n1/2];
    }
    if(n1==0){
        if(n2%2==0)return ((double)nums2[n2/2]+nums2[(n2-1)/2])/2;
        return nums2[n2/2];
    }
    int lb=0,ub=n1;
    int maxLeftX,maxLeftY,minRightX,minRightY;
    while(lb<=ub){
        int x=(lb+ub)/2;   // no. of element in left side in array 1
        int y=(n1+n2+1)/2-x;
        (x>0)?maxLeftX=nums1[x-1]:maxLeftX=INT_MIN;
        (y>0)?maxLeftY=nums2[y-1]:maxLeftY=INT_MIN;
        
        (x!=n1)?minRightX=nums1[x]:minRightX=INT_MAX;
        (y!=n2)?minRightY=nums2[y]:minRightY=INT_MAX;
        
        if(maxLeftX<=minRightY && maxLeftY<=minRightX)break;
        else if(maxLeftX>minRightY)ub=x-1;
        else lb=x+1;
    }
    if((n1+n2)%2!=0)return max(maxLeftX,maxLeftY);
    else{
        double a=max(maxLeftX,maxLeftY);
        double b=min(minRightX,minRightY);
        return (a+b)/2;
    } 
}
double findMedianSortedArrays(const vector<int> &nums1, const vector<int> &nums2) {
    int n1=nums1.size(),n2=nums2.size();
    if(n1>n2){
        return helper(nums2,nums1);
    }
    return helper(nums1,nums2);
}

int main(){
    // call the function
    return 0;
}

