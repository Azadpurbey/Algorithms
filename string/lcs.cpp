#include<bits/stdc++.h>
using namespace std;
int data[1000][1000];
int helper(char *s1,char *s2,int l1,int l2){
	if(l1==0 || l2==0) return 0;
	if(data[l1][l2]!=0)return data[l1][l2];  
	if(s1[0]==s2[0]){
		data[l1][l2]=1+helper(s1+1,s2+1,l1-1,l2-1);
		return data[l1][l2];
	} 
	else{
		int x=helper(s1,s2+1,l1,l2-1);
		int y=helper(s1+1,s2,l1-1,l2);
		data[l1][l2]=max(x,y); 
		return data[l1][l2];
	}
}    

int lcs(string s1, string s2){   //recursive
	int l1=s1.length();
	int l2=s2.length();    
return helper(&s1[0],&s2[0],l1,l2);
}
              
int lcs_iterative(string s1, string s2){  //iterative solution
	int l1=s1.length();
	int l2=s2.length();
	int dp[l1+1][l2+1];
	for(int i=0;i<=l1;i++)dp[i][0]=0;
	for(int i=0;i<=l2;i++)dp[0][i]=0;
		
	for(int i=1;i<=l1;i++){
		for(int j=1;j<=l2;j++){
			if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
    return dp[l1][l2];
}

int main(){
	string s1,s2;
	cin>>s1>>s2;
	cout<<lcs(s1,s2)<<endl;
	cout<<lcs_iterative(s1,s2)<<endl;
	return 0;
}
