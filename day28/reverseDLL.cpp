#include <algorithm>
#include <cstddef>
#include <iostream>
#include <bits/stdc++.h>
#include <stack>
using namespace std;
class Node{
  public:
  int data;
  Node* next;
  Node* back;
  public:
    Node(int data1,Node* next1,Node* back1){
    data=data1;
    next=next1;
    back=back1;
    
    }
    public:
    Node(int data1){
    data=data1;
    next=nullptr;
    back=nullptr;
    }
    };
Node* vector2DLL(vector<int> arr){
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;}
void printDLL(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";}
Node* reverseDLL(Node* head){
    Node* temp=head;
    stack<int> st;
    while(temp){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp){
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }
    return head;}
Node* reverseDLL2(Node* head){
    Node* last=NULL;
    Node* curr =head;
    while(curr!=NULL){
        last=curr->back;
        curr->back=curr->next;
        curr->next=last;
        curr=curr->back;
    }
    return last->back;}
Node* sum2LL(Node* head1,Node* head2){
    Node* temp1=head1;
    Node* temp2=head2;
    Node* dummynode=new Node(-1);
    Node* curr=dummynode;
    int carry=0;
    int sum=0;
    while(temp1!=NULL ||temp2!=NULL){
        sum=carry;
        if(temp1)sum=sum+temp1->data;
        if(temp2)sum=sum+temp2->data;
        Node* newnode=new Node(sum%10);
        carry=sum/10;
        curr->next=newnode;
        curr=curr->next;
        if(temp1)temp1=temp1->next;
        if(temp2)temp2=temp2->next;
    }
    if(carry){
        Node* newnode=new Node(carry);
        curr->next=newnode;
    }
    return dummynode->next;}
Node* OddEven(Node* head){
    vector<int> arr;
    Node* temp=head;
    
    if(head==NULL || head->next==NULL){
        return head;
    }
    while(temp!=NULL && temp->next!=NULL){
        arr.push_back(temp->data);
        temp=temp->next->next;
    }
    if(temp)arr.push_back(temp->data);
    temp=head->next;
    while(temp!=NULL && temp->next!=NULL){
        arr.push_back(temp->data);
        temp=temp->next->next;
    }
    if(temp)arr.push_back(temp->data);
    int i=0;
    temp=head;
    while(temp){
        temp->data=arr[i];
        i++;
        temp=temp->next;
    }
    return head;}
Node* evenodd2(Node* head){
    Node* odd=head;
    Node* even =head->next;
    Node* evenhead=head->next;
    if(head==NULL ||head->next==NULL ){
        return head;
    }
    while(even!=NULL && even->next!=NULL){
        odd->next=odd->next->next;
        even->next=even->next->next;
        odd=odd->next;
        even=even->next;
    }
    odd->next=evenhead;
    return head;
}
int main(){
    vector<int> arr1={2,4,6};
    vector<int> arr2={3,8,7};
    vector<int> arr={1,3,4,2,5,6};
    
    Node* head1 =vector2DLL(arr1);
    Node* head2 =vector2DLL(arr2);
    Node* head=vector2DLL(arr);
    // head1=sum2LL(head1, head2);
    head=evenodd2(head);
    printDLL(head);
}