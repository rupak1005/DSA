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

Node* reverserecur(Node* head){
if(head==NULL||head->next==NULL)return head;

Node* newhead=reverserecur(head->next);
    Node* front=head->next;
    front->next=head;
    head->next=NULL;
    return newhead;
}

Node* add1toLL(Node* head){
    head=reverserecur(head);
    Node* temp=head;
    int carry=1;
    while(temp){
        temp->data=temp->data+carry;
        if(temp->data<10){
            carry=0;
            break;
        }
        else{
            carry=1;
            temp->data=0;
        }
        temp=temp->next;

    }
    if(carry==1){
        Node* newnode=new Node(1);
        head=reverserecur(head);
        newnode->next=head;
        return newnode;
    }
    head=reverserecur(head);
    return head;


}



int addhelper(Node* temp){
    if(temp==NULL){
        return 1;
    }
    int carry=addhelper(temp->next);
    temp->data+=carry;
    if(temp->data<10){
        return 0;
    }
    temp->data=0;
    return 1;
}
Node* add1(Node* head){
    int carry=addhelper(head);
    if(carry==1){
        Node* newnode=new Node(1);
        newnode->next=head;
        head=newnode;
    }
    return head;
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
cout<<"NULL";
}

int main(){
vector<int> arr={9,9,9};
Node* head=vector2LL(arr);
head=add1(head);

printLL(head);
}
//commit
//commit
