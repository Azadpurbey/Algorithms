#include<bits/stdc++.h>
using namespace std;
class points{
  public:  
  double x,y;  
};

class polygon{
 public:
  points *point;
  polygon(int n){
  	point=new points[n];
  }
};
/*
double polygon_area(polygon p,int n){
	double ans=0,x1,x2,y1,y2,hold;
	for(int i=1;i<n-1;i++){
		x1=p.point[i].x-p.point[0].x;
		y1=p.point[i].y-p.point[0].y;
		x2=p.point[i+1].x-p.point[0].x;
		y2=p.point[i+1].y-p.point[0].y;
		hold=x1*y2 - x2*y1;
	}
	ans+=hold;
	return abs(ans)/2;
} */
double polygon_area(polygon p,int n){
	double ans=0,pos=0,neg=0;
	for(int i=0;i<n-1;i++){
        pos+=p.point[i].x *p.point[i+1].y;
        neg+=p.point[i].y *p.point[i+1].x;
	}
    pos+=p.point[n-1].x *p.point[0].y;
	neg+=p.point[n-1].y *p.point[0].x;
    ans=(pos-neg)/2;
    
	return abs(ans);
}

int main() {
 int n;
 cin>>n;
 polygon p(n);
 for(int i=0;i<n;i++)
 	cin>>p.point[i].x;
 
  for(int i=0;i<n;i++)
 	cin>>p.point[i].y;
 //cout<<polygon_area(p,n)<<endl;
 printf("%.1lf",polygon_area(p,n));
 return 0;
	
}