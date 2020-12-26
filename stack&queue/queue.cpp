#include<bits/stdc++.h>
using namespace std;

struct arrayQueue
{
  int Front,rear;
  int capacity;
  int *ar;
};

arrayQueue *createQueue(int Size){
  arrayQueue *Queue=new arrayQueue();
  Queue->Front=-1;
  Queue->rear=-1;
  Queue->capacity=Size;
  Queue->ar=new int[Size];
  return Queue;
}

bool isFull(arrayQueue *Queue){
  if(Queue->rear==(Queue->capacity-1) )
    return true;
  else return false;
}

bool isEmpty(arrayQueue *Queue){
  if(Queue->Front==-1)
    return true;
  else return false;
}

void Insert(arrayQueue *Queue, int x){
  if(isFull){
   cout<<"Queue is full"<<endl;
  }
  else{
        Queue->rear++;
    Queue->ar[Queue->rear]=x;
  }
}

int Delete(arrayQueue *Queue){
 if(!isEmpty){
  int a=Queue->ar[Queue->Front];
   Queue->Front++;
   return a;
 }
 else cout<<"Queue is empty"<<endl;
 return -1;
}

void display(arrayQueue *Queue){
  int lb=Queue->Front;
  int ub=Queue->rear;
  cout<<"present Queue is : ";
  for(int i=lb;i<=ub;i++)
    cout<<Queue->ar[i]<<" ";
   cout<<endl;
}

int main(){
int item,flag=0,n;
arrayQueue *Queue=createQueue(5);
while(1){
 cout<<"press 1: insertion,  press 2: deletion"<<endl;
 cout<<"press any other key for exit";
 cin>>n;
 switch(n){
 case 1:cout<<"enter element : ";
        cin>>item;
        Insert(Queue,item);
        display(Queue);   break;
 case 2:Delete(Queue);
        display(Queue);  break;
 default:  display(Queue);flag=1;
 }
if(flag==1) break;

}
return 0;
}
