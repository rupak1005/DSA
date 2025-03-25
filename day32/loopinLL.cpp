
#include <bits/stdc++.h>
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


bool detectCycle(Node *head)
{
	Node* fast=head;
    Node* slow=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)return true;
    }
    return false;
}

Node* vector2LL(vector<int> &arr){
Node* head=new Node(arr[0]);
Node* prev =head;
for(int i=1;i<arr.size();i++){
    Node* temp=new Node(arr[i]);
    prev->next=temp;
    prev=temp;
}
return head;
}

void PrintLL(Node* head){
Node* temp=head;
while(temp!=NULL){
    cout<<temp->data<<"->";
    temp=temp->next;
}
cout<<"NULL";
}
int main(){
    vector<int> arr1={1,2,3,4,5,6,7};
    vector<int> arr2={4,5,6,7};
    Node* head=vector2LL(arr1);
    
    cout<<detectCycle(head);
    
   

}