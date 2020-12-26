#include<bits/stdc++.h>
using namespace std;

int postfixevaluation(string s)
{
stack<int> st;
int l=s.length();
for(int i=0;i<l;i++){
if(s[i]>='0'&&s[i]<='9')
st.push(s[i]-'0');
else{
char a=st.top();
st.pop();
char b=st.top();
st.pop();
switch(s[i]){
case '+':st.push(a+b);break;
case '-':st.push(b-a);break;
case '*':st.push(a*b);break;
case '/':st.push(b/a);break;
}
}
}
return st.top();
}

int main()
{
string s="231*+9-";
cout<<"Postfix evaluation: "<<postfixevaluation(s);
return 0;
}
