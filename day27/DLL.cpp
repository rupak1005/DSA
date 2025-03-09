#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;
    
    Node(int data1,Node* next1,Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }
    
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
        
    }    };
Node* array2Dll(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;}
Node* deleteHead(Node* head){
    
    if(head==NULL || head->next==NULL)return NULL;
    Node* prev=head;
    head=head->next;
    head->back=NULL;
    prev->next=NULL;
    delete prev;
    return head;    }
Node* deleteTail(Node* head){
    if(head==NULL || head->next==NULL)return NULL;
    Node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    Node* newtail =tail->back;
    newtail->next=NULL;
    tail->back=NULL;
    delete tail;
    return head;}
Node* deleteK(Node* head,int k){
    if(head==NULL)return NULL;
    Node* temp =head;
    int cnt=0;
    while(temp!=NULL ){
        cnt++;
        if(cnt==k)break;
        temp=temp->next;
    }
    Node* prev=temp->back;
    Node* front=temp->next;
    if(prev==NULL ||front==NULL){
        
        return NULL;
        
    }
    else if(prev==NULL){
        head=deleteHead(head);
        return head;
    }
    else if(front==NULL){
        head=deleteTail(head);
        return head;
    }else{
        prev->next=front;
        front->back=prev;
        temp->next=NULL;
        temp->back=NULL;
        delete temp;
        return head;
    }}
void deleteNode(Node* temp){
    Node* prev=temp->back;
    Node*front=temp->next;
    if(front==NULL){
        prev->next=NULL;
        temp->back=NULL;
        delete temp;
        return ;
        
    }
    prev->next=front;
    front->back=prev;
    temp->next=temp->back=NULL;
    delete temp;
    return;}
Node* insertbeforeHead(Node* head ,int val){
    Node* newhead=new Node(val,head,nullptr);
    head->back=newhead;
    return newhead;}
Node* insertBeforeTail(Node*head, int val){
    if(head->next==NULL){
        return insertbeforeHead(head,  val);
    }
    Node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    Node* prev=tail->back;
    Node* newnode=new Node(val,tail,prev);
    prev->next=newnode;
    tail->back=newnode;
    return head;}
Node* insertBeforeKthElement(Node* head,int k,int val){
    if(k==1){
        return insertbeforeHead(head,  val);
    }
    int cnt=0;
    Node* temp=head;
    while(head){
        cnt++;
        
        if(cnt==k)break;
        temp=temp->next;
    }
    Node* prev=temp->back;
    Node* newnode=new Node(val,temp,prev);
    prev->next=newnode;
    temp->back=newnode;
    return head;}
void insertbeforeNode(Node* node,int val){
    Node* prev=node->back;
    Node* newnode=new Node(val,node,prev);
    prev->next=newnode;
    node->back=newnode;}
void printDll(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";}
int main(){
    vector<int> arr={1,2,3,4,5,6};
    Node* head=array2Dll(arr);
    head=insertBeforeKthElement(head,2,10);
    insertbeforeNode(head->next, 69);
    printDll(head);
}

