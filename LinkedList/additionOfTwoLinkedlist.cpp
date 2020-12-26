#include<bits/stdc++.h>  // number is stored in reverse order in linkedList
using namespace std;
struct Node{
    int val;
    Node *next=NULL;
};
Node* createNode(int x){
    Node *temp=new Node();
    temp->val=x;
    temp->next=NULL;
    return temp;
}
// void traverse(Node* root){
//     if(root==NULL)return;
//     cout<<root->val<<" ";
//     traverse(root->next);
// }
void traverse(Node* root){
  Node* temp=root;
  cout<<"Traversal of Linked List"<<":";
  while(temp!=NULL){
    cout<<temp->val<<" ";
    temp=temp->next;
  }
  cout<<endl;
}
Node* addation1(Node *a,Node *b){       
    if(b==NULL)return a;
    if(a==NULL)return b;
    Node* temp=createNode(a->val+b->val);
    temp->next=addation1(a->next,b->next);
    return temp;
}
Node *digitConversion(Node* head,int rem){
  Node * temp;
  if(head==NULL && rem==0)return NULL;
  if(head==NULL){
    temp=createNode(rem%10);
    rem=rem/10;
    temp->next=digitConversion(head,rem);
    return temp; 
  }
  temp=createNode((head->val+rem)%10);
  rem=(head->val+rem)/10;
  temp->next=digitConversion(head->next,rem);
  return temp;
}


int main(){
  Node *root=createNode(1);
  root->next=createNode(2);
  root->next->next=createNode(3);
  root->next->next->next=createNode(4);
  Node*temp=root->next->next->next;
  temp->next=createNode(6);
  temp->next->next=createNode(7);
  temp->next->next->next=createNode(8);

  Node *root1=createNode(10);
  root1->next=createNode(1);
  root1->next->next=createNode(1);
  root1->next->next->next=createNode(1);

  Node *ans=NULL,*ans1=NULL;
  traverse(root);
  traverse(root1);
  ans1=addation1(root,root1);
  traverse(ans1);  // digits are not converted into single

  ans1=digitConversion(ans1,0);
  traverse(ans1);
  return 0;
}

// class Solution {  Another precise method
// public:
//     Node* addTwoNumbers(Node* l1, Node* l2) {
//         int rem=0;
//         Node *temp=new Node();
//         Node *ans=temp;
//         while(l1!=NULL || l2!=NULL){
//             if(l1!=NULL){
//                 rem+=l1->val;
//                 l1=l1->next;
//             }
//             if(l2!=NULL){
//                 rem+=l2->val;
//                 l2=l2->next;
//             }
//             Node *hold=new Node();
//             hold->val=rem%10;
//             rem/=10;
//             temp->next=hold;
//             temp=temp->next; 
//         }
//         if(rem==1){
//            Node *hold=new Node();
//             hold->val=rem%10; 
//             temp->next=hold;
//         }
//         return ans->next;
//     }
// };