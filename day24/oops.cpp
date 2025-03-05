#include <iostream>
#include <string>
using namespace std;
class Teacher {

    private:
double salary;

    public:
    //properties/ attributes
    string name;
    string dept;
    string subject;
    

// Teacher(){
//     cout<<"Yo, wassup constructor this side"<<endl;
// }


Teacher(string name,string dept,string subject,double salary){
    cout<<"Yo, wassup constructor this side"<<endl;
    this->name=name;
    this->dept=dept;
    this->subject=subject;
    this->salary=salary;
}

//copy constructor

Teacher(Teacher &orgObj) {
     cout<<"Yo, copy constructor this side"<<endl;
this->name = orgObj.name;
this->dept = orgObj.dept;
this->subject = orgObj.subject;
this->salary = orgObj.salary;
}
//methods/ member functions

void changeDept (string newdept) {
dept = newdept;
}


// setter
void setSalary(double s){
    salary=s;
}

// getter
double getSalary(){
    return salary;
}
void getinfo(){
    cout<<"name :"<<name<<endl;
    cout<<"subject :"<<subject<<endl;
    cout<<"salary :"<<salary<<endl;
    cout<<"dept :"<<dept<<endl;
}
};


int main(){
    // Teacher t1;
    Teacher t1("rupak","CSE","computer science",25000);
    // t1.name="rupak";
    // t1.dept="CSE";
    // t1.subject="C++";
    // t1.setSalary(25000);
    // t1.getinfo();
    Teacher t2(t1);//custom copy constructor
    t2.getinfo();
    // cout<<t1.name<<endl;
    // cout<<t1.getSalary();
  
    return 0;
}