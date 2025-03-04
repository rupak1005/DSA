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
};
int main(){
    Teacher t1;
    t1.name="rupak";
    t1.dept="CSE";
    t1.subject="C++";
    t1.setSalary(25000);
    
    cout<<t1.name<<endl;
    cout<<t1.getSalary();
    
    return 0;
}