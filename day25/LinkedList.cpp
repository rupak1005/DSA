#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
    
};

class List{
    Node* head;
    Node* tail;
    
    public:
    List(){
        head=NULL;
        tail=NULL;
    }
    void push_front(int val){
        Node* newnode=new Node(val);
        if(head==NULL){
            head=tail=newnode;
            return;
        }
        else{
            newnode->next=head;
            head=newnode;
        }
    }
    
    
    void push_back(int val){
        Node* newnode=new Node(val);
        if(head==NULL){
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
            
        }
    }
    
    
    void pop_front(){
        
        if(head==NULL){
            return;
        }
        
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    
    void pop_back(){
       if(head==NULL){
           cout<<"ll is empty";
       }
       if(head==tail){
           head=tail=NULL;
           return;
       }
       Node* temp=head;
       while(temp->next->next != NULL){
           temp=temp->next;
       }
       temp->next=NULL;
       delete tail;
       tail=temp;
       tail->next=NULL;
      
        
    }
    
    
    
    void insert(int val,int pos){
        if(pos<0){
            cout<<"invalid pos\n";
            return;
            
        }
        if(pos==0){
            push_front(val);
            return;
        }
        Node* temp=head;
        for(int i=0;i<pos-1;i++){
            if (temp == NULL) { // If position is out of range
                        cout << "Position out of range\n";
                        return;
                    }
            temp=temp->next;
        }
        if (temp == NULL) { // If trying to insert beyond the last element
                cout << "Position out of range\n";
                return;
            }

        Node* newnode =new Node(val);
        newnode->next=temp->next;
        temp->next=newnode;
        
        // If inserted at the end, update the tail
            if (newnode->next == NULL) {
                tail = newnode;
            }
    }
    
    
   int search(int val){
        Node* temp=head;
        
        int idx=0;
        while(temp!=NULL){
            if(temp->data==val){
                return idx;
                
            }
            temp=temp->next;
            idx++;
        }
        return -1;
        
    }
    void printll(){
        Node* temp=head;
        
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
        
    }
    
};


int main(){
    List ll;
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.insert(5,0);
    cout<<ll.search(2);
    ll.printll();
}