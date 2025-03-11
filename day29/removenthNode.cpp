#include <algorithm>
#include <cmath>
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
    Node* removenthNodefromback(Node* head, int n) {
        if (!head) return nullptr; // Edge case: empty list
    
        Node* temp = head;
        int cnt = 0;
        
        // Count the total number of nodes
        while (temp) {
            cnt++;
            temp = temp->next;
        }
    
        // If we need to remove the head node
        if (cnt == n) {
            Node* newhead = head->next;
            delete head;
            return newhead;
        }
    
        int res = cnt - n; // Find the node before the one we need to delete
        temp = head;
    
        // Traverse to the node before the one we need to remove
        for (int i = 1; i < res; i++) {
            temp = temp->next;
        }
    
        // Delete the target node
        Node* delnode = temp->next;
        temp->next = delnode->next;
        delete delnode;
    
        return head;
    }
    
    Node* removeNthFromthebackOP(Node* head,int n){
        Node* fast=head;
        Node*slow=head;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        if(fast==NULL){
            Node* newhead=head->next;
            delete head;
            return newhead;
        }
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        
        Node* delnode=slow->next;
        slow->next=slow->next->next;
        delete delnode;
        return head;
    }
    int main(){
        vector<int> arr={2,1,1,0,0,0,2};
        Node* head=vector2DLL(arr);
        head=removeNthFromthebackOP(head,7);
        
        printDLL(head);
        
    }