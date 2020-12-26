#include<bits/stdc++.h>
using namespace std;
int Rank(char a){
    if(a=='+' || a=='-')return 1;
    if(a=='*' || a=='/')return 2;
    if(a=='^')return 3;
    return -1;
}

string infix_to_postfix(string infix){
    int n=infix.length();
    string postfix;
    cout<<infix<<endl;
    stack<char>stk;
    for(int i=0;i<n;i++){
        char cur=infix[i];
        if((cur>='a' && cur<='z') || (cur>='A' && cur<='Z')){
            postfix+=cur;
        } 
        else if(cur=='('){
            stk.push(cur);
        }
        else if(cur==')'){
            while(stk.top()!='('){
                postfix+=stk.top();
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
                    postfix+=stk.top();
                    stk.pop();
                }
                while(!stk.empty() && Rank(cur)==Rank(stk.top())){
                    postfix+=stk.top();
                    stk.pop();
                }
                stk.push(cur);
            }
            else{
                if(cur=='^'){
                    stk.push(cur);
                }
                else{
                    while(!stk.empty() && Rank(cur)==Rank(stk.top())){
                        postfix+=stk.top();
                        stk.pop();
                    }
                    stk.push(cur); 
                }
            }
        }
    } 
    while(!stk.empty()){
        postfix+=stk.top();
        stk.pop();
    }
    return postfix;
}


int main(){
    freopen("input.txt","r",stdin);
    string infix;
    cin>>infix;
    cout<<infix_to_postfix(infix);
    
    return 0;
}