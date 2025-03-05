#include <iostream>
#include <string>

using namespace std;

class Person {
public:
string name;
int age;

Person(string name, int age) {

this->name = name;
 this->age = age;
}

Person() {

    cout << "parent constructor..\n";}};

class Student :public Person{ 
  public:
  int rollno;
  
  Student(string name,int age,int rollno) :Person(name,age){
      cout<<"yo child constructor..\n";
      this->rollno=rollno;
  }

void getinfo(){
cout<<"name :"<<name<<endl;
cout<<"age:"<<age<<endl;
cout<<"rollno :"<<rollno<<endl;}
};

int main(){
    
    Student s1("rupak",21,1234);
    // s1.name="rupak";
    // s1.age=21;
    // s1.rollno=1234;
    s1.getinfo();
}