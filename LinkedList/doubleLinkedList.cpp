#include<iostream>
using namespace std;
struct Node{
int data;
Node *left;
Node *right;
 };

Node *getNode(int x){
 Node *temp=new Node();
 temp->data=x;
 temp->left=NULL;
 temp->right=NULL;
 return temp;
}

Node* insert(Node *head,int item,int pos){
Node *temp=getNode(item);
if(pos==1){
   if(head==NULL)
    head=temp;
    else{
  Node *temp1=head;
  temp1->left=temp;
  temp->right=temp1;
  head=temp;
    }
}

else{
 Node *temp1=head;
 for(int i=1;i<pos-1;i++)
  temp1=temp1->right;
  Node *temp2=temp1->right;
  temp->right=temp2;
  temp->left=temp1;
  temp1->right=temp;
  temp2->left=temp;
 }
 return head;
}
Node* Delete(Node *head,int pos){
Node *temp1=head;
if(pos==1){
head=temp1->right;
Node *temp2=temp1->right;
temp2->left=NULL;
delete(temp1);
 }
else{
 for(int i=1;i<pos-1;i++)
   temp1=temp1->right;
Node *temp2,*temp3;
 temp2=temp1->right;
 temp3=temp2->right;
 temp1->right=temp3;
 temp3->left=temp1;
 delete(temp2);
 }
 return head;
}
void display(Node *head){
cout<<"present list is ";
Node *temp=head;
while(temp!=NULL){
 cout<<temp->data<<" ";
  temp=temp->right;
 }
cout<<endl;
}

void rDisplay(Node *head){
cout<<"present list is ";
Node *temp=head;
while(temp->right!=NULL)
  temp=temp->right;
while(temp->left!=NULL){
 cout<<temp->data<<" ";
  temp=temp->left;
 }
  cout<<temp->data<<" ";
cout<<endl;
}


int main(){
int n,item,pos,flag=0;
Node *a=NULL;
while(1){
 cout<<"press 1: insertion ,press 2: deletion ,press 3: reverse display ,press any other key for exit"<<endl;
 cin>>n;
 switch(n){
 case 1:cout<<"enter element and position"<<endl;
        cin>>item>>pos;
        a=insert(a,item,pos);
        display(a);
        break;
 case 2:cout<<"position where you want deletion";
        cin>>pos;
        a=Delete(a,pos);
        display(a);break;
 case 3:rDisplay(a);break;
 default:  display(a);flag=1;
 }
if(flag==1) break;

}
return 0;
}
