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



Node* intersectionPoint(Node* head1,Node* head2){
    if(head1==NULL||head2==NULL)return NULL;
    Node* temp1=head1;
    Node* temp2=head2;
    while(temp1!=temp2){
        temp1=temp1->next;
        temp2=temp2->next;
        if(temp1==temp2)return temp1;
        if(temp1==NULL)temp1=head2;
        if(temp2==NULL)temp2=head1;
    }
    return temp1;
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
    Node* head1=vector2LL(arr1);
    Node* head2=vector2LL(arr2);
    Node* head=intersectionPoint(head1, head2);
    PrintLL(head);

}