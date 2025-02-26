#include <iostream>
#include <string>
using namespace std;


string removeOccurrences(string &s, string part){
    while(s.length() && s.find(part)<s.length()){
                
                s.erase(s.find(part),part.length());        }
               
            return s;
        } 
          
    

int main(){
    string s = "daabcbaabcbc", part = "abc";
    removeOccurrences(s,part);
    cout<<s;
}