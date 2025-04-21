#include<bits/stdc++.h>
using namespace std;

class Stack{
    int size;
    int *arr;
    int top;
    public:
    Stack(){
        top=-1;
        size=100;
        arr=new int[size];
    }
    void push(int x){
        top++;
        arr[top]=x;
    }
    int Top(){
        return arr[top];
    }
    int pop(){
        int x=arr[top];
        top--;
        return x;
    }
    int Size(){
        return top+1;
    }
};


int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout<<s.Top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.Size()<<endl;
    
    
}