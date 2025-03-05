#include <iostream>
#include <string>


using namespace std;


class Student{
    public:
    string name;
    double *cgpaptr;
  
  
  Student(string name,double cgpa){
      
      cout<<"yo contructor called!!"<<endl;
      this->name=name;
      cgpaptr=new double;
      *cgpaptr=cgpa;
      
  }  
  
  ~Student(){
      cout<<"yo destructor called!!"<<endl;
      delete cgpaptr; //memory leak
  }
  
  void getInfo(){
      cout<<"name: "<<name<<endl;
      cout<<"cgpa: "<<*cgpaptr<<endl;
  }
};

int main(){
    Student s1("rupak",7.5);
    s1.getInfo();
    
    
}
