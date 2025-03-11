#include <algorithm>
#include <cstddef>
#include <cstdio>
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
    
    
    Node* sort012(Node* head){
        Node* temp=head;
        int cnt0=0;
        int cnt1=0;
        int cnt2=0;
        while(temp!=NULL){
            if(temp->data==0)cnt0++;
            else if(temp->data==1)cnt1++;
            else{
                cnt2++;
            }
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
            if(cnt0){
                temp->data=0;
                cnt0--;
            }else if(cnt1){
                temp->data=1;
                cnt1--;
            }
            else{
                temp->data=2;
            }
            temp=temp->next;
        }
        return head;
    }
    
    Node* sort012OP(Node* head){
        Node* zerohead=new Node(-1);
        Node* onehead=new Node(-1);
        Node* twohead=new Node(-1);
        Node* zero=zerohead;
        Node* one=onehead;
        Node* two=twohead;
        Node* temp=head;
        while(temp){
            if(temp->data==0){
                zero->next=temp;
                zero=temp;
            }
            else if(temp->data==1){
                one->next=temp;
                one=temp;
            }
            else{
                two->next=temp;
                two=temp;
            }
            temp=temp->next;
            
        }
        zero->next=(onehead->next)?onehead->next:twohead->next;
        one->next=(twohead->next);
        two->next=NULL;
        return zerohead->next;
        
    }
    int main(){
        vector<int> arr={2,1,1,0,0,0,2};
        Node* head=vector2DLL(arr);
        head=sort012OP(head);
        
        printDLL(head);
        
    }