#include<bits/stdc++.h>
#include<set>
using namespace std;

struct arrayStack{
  int maxsize;
  int top;
  int *ar;
};

arrayStack *createStack(int size){
	arrayStack *stack=new arrayStack();
	stack->maxsize=size;
	stack->top=-1;
	stack->ar=new int[size];
	return stack;
}

bool isEmpty(arrayStack *stack){
	if(stack->top==-1)
		return true;
	else return false;
}

void push(arrayStack *stack,int item){
 if(stack->top==stack->maxsize-1)
 	cout<<"overflow"<<endl;
 else{
 	stack->top++;
 	stack->ar[stack->top]=item;
 }
}

int pop(arrayStack *stack){
	int item=-1;
	if( isEmpty(stack) )
		cout<<"underflow"<<endl;
	else{
		item=stack->ar[stack->top];
		stack->top--;
	}
	return item;
}

void display(arrayStack *stack){
	int n=stack->top;
	for (int i = 0; i <= n; ++i)
    cout<<stack->ar[i]<<" ";
    cout<<endl;
}

int main(){
int n,item;
cout<<"enter max size of stack"<<endl;
cin>>n;
arrayStack *stack= createStack(n);

while(1){
 cout<<"press 1 for insertion, 2 for deletion, any other key for exit"<<endl;
 cin>>n;
 if(n==1){
    cout<<"enter element which you want to insert";
    cin>>item;
 	push(stack,item);
 	cout<<"present stack is"<<endl;
 	display(stack);
 }
  else if(n==2){
 	item=pop(stack);
 	cout<<"present stack is"<<endl;
 	display(stack);
 }
 else break;

}

  return 0;
}
