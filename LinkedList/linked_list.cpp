#include<iostream>
using namespace std;

struct Node{
    Node* next;
    int val;
};
void insert(Node* &head,int value,int pos){
    Node *temp=new Node;
    temp->val=value;
    temp->next=NULL;
    Node *p=head;
    if(p==NULL){
        head=temp;
        return ;
    }
    if(pos==1){
        head=temp;
        temp->next=p;
    }
    else{
        for(int i=2;i<pos;i++){
            p=p->next;
        }
        temp->next=p->next;
        p->next=temp;
    }
}
void Delete(Node* &head,int pos){
    Node *p=head;
    if(p->next==NULL)head=NULL;
    if(pos==1){
        head=p->next;
    }
    else{
        for(int i=2;i<pos;i++){
            p=p->next;
        }
        p->next=p->next->next;
    }
}

void display(Node *head){
    Node *p=head;
    if(p==NULL)cout<<"No element is present"<<endl;
    else cout<<"present list : ";
    while(p!=NULL){
        cout<<p->val<<" ";
        p=p->next;
    }
    cout<<endl;
}
int number_of_element(Node* head){
    int cont=0;
    Node *p=head;
    while(p!=NULL){
        cont++;
        p=p->next;
    }
    return cont;
}
void reverse(Node* &head){
    Node  *prev=NULL,*cur=head,*Next=cur->next;
    // Node* cur=head;
    // Node* Next=cur->next;
    while(Next!=NULL){
        cur->next=prev;   //reverse
        prev=cur;
        cur=Next;
        Next=Next->next;
    }
    cur->next=prev; 
    head=cur;
}
int main(){
    Node *head=NULL;
    insert(head,2,1);
    insert(head,4,2);
    insert(head,1,1);
    insert(head,1,1);
    insert(head,5,3);display(head);
    reverse(head);display(head);
    
    
    return 0;
}