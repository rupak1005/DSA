#include <iostream>
#include <string>
using namespace std;

// class Person {

// public:
// string name;
// int age;

// };

// class Student : public Person {
// public:

// int rollno;
// };

// class GradStudent : public Student {
// public:
// string researchArea;
// void getinfo(){
//     cout<<name<<"\n";
//     cout<<rollno<<"\n";
//     cout<<researchArea<<"\n";
// }
// };



class Student{
    public:
    string name;
    int rollno;
    
};


class Teacher{
    public:
    string subject;
    double salary;
};



class TA:public Student,public Teacher{
    public:
   void getinfo(){
       cout<<name<<"\n";
       cout<<rollno<<"\n";
       cout<<subject<<"\n";
       cout<<salary<<"\n";
   }
    
};
int main(){
    TA t1;
    t1.name="rupak";
    t1.rollno=1234;
    t1.subject="cs";
    t1.salary=350000;
    t1.getinfo();
    
    // GradStudent g1;
    // g1.name="tony";
    // g1.rollno=1234;
    // g1.researchArea="quantum physics";
    // g1.getinfo();
}