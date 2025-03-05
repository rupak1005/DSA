#include<iostream>
#include <string>
using namespace std;

class Student{
    public:
    string name;
    double *cgpaptr;
    
    Student(string name,double cgpa){
        this->name=name;
        // this->cgpa=cgpa;
        cgpaptr=new double;
        *cgpaptr=cgpa;
    }
    
    Student(Student &obj){
        this->name=obj.name;
        cgpaptr=new double;
        *cgpaptr=*obj.cgpaptr;
    }
    
    void getInfo(){
        cout<<"name : "<<name<<"\n";
        cout<<"cgpa : "<<*cgpaptr<<endl;
    }
};



int main(){
    Student s1("rupak",7.5);
    s1.getInfo();
    Student s2(s1);
    s2.name="neha";
    cout<<endl;
    *(s2.cgpaptr)=9.2;
    s2.getInfo();
    
}