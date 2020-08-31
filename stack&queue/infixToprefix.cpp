#include<bits/stdc++.h>
using namespace std;
int Rank(char a){
    if(a=='+' || a=='-')return 1;
    if(a=='*' || a=='/')return 2;
    if(a=='^')return 3;
    return -1;
}

string infix_to_prefix(string infix){
    int n=infix.length();
    string prefix;
    reverse(infix.begin(),infix.end());
    cout<<infix<<endl;
    stack<char>stk;
    for(int i=0;i<n;i++){
        if(infix[i]=='(')infix[i]=')';
        if(infix[i]==')')infix[i]='(';
    }
    for(int i=0;i<n;i++){
        char cur=infix[i];
        if((cur>='a' && cur<='z') || (cur>='A' && cur<='Z')){
            prefix+=cur;
        } 
        else if(cur=='('){
            stk.push(cur);
        }
        else if(cur==')'){
            while(stk.top()!='('){
                prefix+=stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else{
            if(stk.empty()){
                stk.push(cur);
            }
            else if(Rank(cur)>Rank(stk.top())){
                stk.push(cur);
            }
            else if(Rank(cur)<Rank(stk.top())){
                while(!stk.empty() && Rank(cur)<Rank(stk.top())){
                    prefix+=stk.top();
                    stk.pop();
                }
                stk.push(cur);
            }
            else{
                if(cur=='^'){
                    while(!stk.empty() && cur=='^' && Rank(cur)==Rank(stk.top())){
                        prefix+=stk.top();
                        stk.pop();
                    }
                    stk.push(cur);
                }
                else{
                    stk.push(cur); 
                }
            }
        }
    } 
    while(!stk.empty()){
        prefix+=stk.top();
        stk.pop();
    }
    cout<<prefix<<endl;
    reverse(prefix.begin(),prefix.end());
    cout<<prefix<<endl;
    return prefix;
}


int main(){
    freopen("input.txt","r",stdin);
    string infix;
    cin>>infix;
    cout<<infix_to_prefix(infix);
    
    return 0;
}