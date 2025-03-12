#include<bits/stdc++.h>
#include <stack>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
        
    }
    Node(int data1){
        data=data1;
        next=nullptr;
    }
    
    
};
bool ispalindrome(Node* head){
    Node*temp=head;
    stack<int> st;
    while(temp){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp){
        if(st.top()==temp->data){
            
            st.pop();
            temp=temp->next;
        }
        else{
            return false;
        }
    }
    return true;
}
Node* reverserecur(Node* head){
    if(head==NULL||head->next==NULL)return head;

Node* newhead=reverserecur(head->next);
        Node* front=head->next;
        front->next=head;
        head->next=NULL;
        return newhead;
    }


bool ispalindromeOP(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* newhead=reverserecur(slow->next);
    Node* first=head;
    Node* second=newhead;
    while(second!=NULL){
        if(first->data!=second->data){
            reverserecur(newhead);
            return false;
        }
        else{
            first=first->next;
            second=second->next;
        }
        
    }
    reverserecur(newhead);
    return true;
    
}
Node* vector2LL(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        prev->next=temp;
        prev=temp;
    }
    return head;
}
void printLL(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}


int main(){
    vector<int> arr={1,2,3,2,1};
    Node* head=vector2LL(arr);
    
    
    cout<<ispalindromeOP(head);
    
}