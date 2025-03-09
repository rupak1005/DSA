#include <algorithm>
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
int main(){
    vector<int> arr={2,3,4,1};
    Node* head =vector2DLL(arr);
    head=reverseDLL(head);
    printDLL(head);
}