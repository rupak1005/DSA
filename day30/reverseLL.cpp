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

    Node* reverseLL(Node* head) {
        if (!head || !head->next) return head; // Edge case: empty list or single node
        
        Node* temp = head;
        std::stack<int> st;
        
        // Push all node values onto the stack
        while (temp) {
            st.push(temp->data);
            temp = temp->next;
        }
        
        // Assign values back in reverse order
        temp = head;
        while (temp) {
            temp->data = st.top();
            st.pop();
            temp = temp->next;
        }
        
        return head;  // Return the head of the reversed list
    }
    
    Node* reverseLLOP(Node* head){
        Node*temp=head;
        Node*prev=NULL;
        while(temp){
            Node* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    
    Node* reverserecur(Node* head){
        if(head==NULL||head->next==NULL)return head;
    
    Node* newhead=reverserecur(head->next);
            Node* front=head->next;
            front->next=head;
            head->next=NULL;
            return newhead;
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
    vector<int> arr={2,1,1,0,0,0,2};
    Node* head=vector2LL(arr);
    head=reverserecur(head);
    
    printLL(head);
    
}