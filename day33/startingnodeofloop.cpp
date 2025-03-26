#include <bits/stdc++.h>
#include <map>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};




Node* startingpointofloop(Node* head){
    map<Node*,int> m;
    Node* temp= head;
    while(temp){
        if(m.find(temp)!=m.end()){
            return temp;
        }
        m[temp]=1;
        temp=temp->next;
    }
    return NULL;
}

Node *firstNode(Node *head)
{
    Node* slow=head;
    Node* fast=head;
    if(fast==NULL && fast->next==NULL)return NULL;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast){
            slow=head;
            while(slow!=fast){;
            fast=fast->next;
            slow=slow->next;}
            return fast;
        }
    }
    return NULL;
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
   head=firstNode(head);
   PrintLL(head);
   
  

}