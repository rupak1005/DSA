#include <iostream>
#include <string>
using namespace std;

class Student{
    public:
    string name;
    Student(){
        cout<<"non-parameterized constructor";
    }
    Student(string name){
        this->name=name;
        cout<<"parametererized constructor";
    }
};

class Print {
public:
void show(int x) {
    cout << "int : " << x << endl;}

void show(char ch) {
cout << "char : " << ch << endl;}

};

int main(){
    // Student s1;
    // Student s2("rupak");
    Print p1;
    p1.show(101); //function overloading
    p1.show('$');
    
    
    
    return 0;
}