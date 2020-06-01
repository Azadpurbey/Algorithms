#include<bits/stdc++.h>
using namespace std;
struct points{
long long int x,y;
 
};
bool tochange(points p,points q,points r){
long long int x1 = q.x - p.x;
long long int y1  = q.y - p.y;
long long int x2 = r.x - q.x;
long long int y2  = r.y - q.y;
 
long long int value = x1*y2 - y1*x2;
 
return value<0;
 
}
void convexHull(points point[],long long int n){
    vector<points> hull;
    long long int left = 0;
 
    for(long long int i=1; i<n; i++){
        if(point[i].x < point[left].x){
            left = i;
        }
    }
    long long int p = left;
    do{
        hull.push_back(point[p]);
        long long int q = (p+1)%n;
        for(long long int i=0; i<n; i++){
            if(tochange(point[p],point[q],point[i])){
                q = i;
            }
        }
        p= q;
 
    }while(p!=left);
 
   for(long long int i=0; i<hull.size(); i++){
        cout<<hull[i].x<<" "<<hull[i].y<<endl;
    }
}
int main(){
    long long int n;
    cin>>n;
    points point[n];
    for(long long int i=0; i<n; i++)
    cin>>point[i].x;
    for(long long int i=0; i<n; i++)
    cin>>point[i].y;
    convexHull(point,n);
}