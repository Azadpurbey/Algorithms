#include<bits/stdc++.h>
using namespace std;

int prec(char ch){
if(ch=='^')
return 3;
else if(ch=='*'||ch=='/')
return 2;
else if(ch=='+'||ch=='-')
return 1;
else
return -1;
}

void infixtopostfix(string s){
stack<char> st;
st.push('#');
int l=s.length();
string ns;
for(int i=0;i<l;i++)
{
if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
ns+=s[i];
else if(s[i]=='(')
st.push('(');
else if(s[i]==')')
{
while(st.top()!='#'&&st.top()!='(')
{
char c=st.top();
ns+=c;
st.pop();
}
if(st.top()=='(')
st.pop();
}
else
{
while(st.top()!='#'&&prec(s[i])<=prec(st.top()))
{
char c=st.top();
st.pop();
ns+=c;
}
st.push(s[i]);
}
}
while(st.top()!='#')
{
char c=st.top();
st.pop();
ns+=c;
}
cout<<ns<<endl;
}

int main()
{
string s="a+b*(c^d-e)^(f+g*h)-i";
infixtopostfix(s);
return 0;
}
