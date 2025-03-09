#include <cstddef>
#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    public:
    
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    
    Node(int data1){
        data=data1;
        next=NULL;
    }

};

Node* array2ll(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp =new Node(arr[i]);
        mover->next=temp;
        mover=mover->next;
    }
    return head;
}

Node* deleteHead(Node* head)
{
    if(head==NULL ){
        return head;
    }
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
}

Node* deleteTail(Node* head){
    if(head==NULL || head->next==NULL)return NULL;
    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
    return head;
}
int lengthOfLL(Node* head){
    int cnt=0;
    Node* temp=head;
    while(temp){
        cnt++;
        temp=temp->next;
    }
    return cnt;
    
}
void printLL(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}

Node* deleteK(Node*head,int k){
    if(head==NULL)return head;
    if(k==1){
        Node*temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    int cnt=0;
    Node* temp=head;
    Node*prev=NULL;
    while(temp){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
        
    }
    return head;
}
Node* insertHead(Node* head,int val){
    Node* temp=new Node(val,head);
    return temp;
}



Node* insertTail(Node* head,int val){
    if(head==NULL){
        return new Node(val);
    }
    Node* temp=head;
    Node* newnode= new Node(val);
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    return head;
}

Node* insertK(Node* head,int  el,int k){
    if(head==NULL){
        if(k==1){
            return new Node(el);
        }
        else{return NULL;}
    }
    if(k==1){
        return new Node(el,head);
    }
    int cnt=0;Node* temp=head;
    while(temp){
        cnt++;
        if(cnt==k-1){
            Node* newnode=new Node(el,temp->next);
            // newnode->next=temp->next;
            temp->next=newnode;
            break;
        }
        temp=temp->next;
    }
    return head;
}

Node* insertBeforeval(Node* head,int  el,int val){
    if(head==NULL){
        return NULL;
    }
    if(head->data ==val){
        return new Node(val,head);
    }
    Node* temp=head;
    while(temp->next!=NULL){
        if(temp->next->data==val){
            Node* newnode=new Node(el,temp->next);
            temp->next=newnode;
            break;
        }
        temp=temp->next;
    }
   
return head;    
    }
    

int main(){
    vector<int> arr={1,2,3,4,5,6};
    Node* y=new Node(arr[0]);
    Node* head=array2ll(arr);
    cout<<"original ll:"<<endl;
    printLL(head);
    
    
    // cout<<"\nlength of ll = "<<lengthOfLL(head);
    cout<<endl;
    // cout<<"delete head ll:"<<endl;

    // head=deleteHead(head);
    // printLL(head);
    // cout<<endl;
    // cout<<"delete tail ll:"<<endl;

    // head=deleteTail(head);
    // printLL(head);
    // head=deleteK(head,3);
    // cout<<"after deletion:\n";
    // printLL(head);
    // head=insertHead(head, 100);
    
    // or
    // head=new Node(100,head);
    // printLL(head);
    // head=insertTail(head, 100);
    // printLL(head);
    // head=insertBeforeval(head,100,5);
    // printLL(head);
    
    

}