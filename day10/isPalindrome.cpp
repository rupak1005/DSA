#include <iostream>
#include <string>
using namespace std;





    bool isAlphaNum(char c){
        if(c>='0' && c<='9'){
            return true;
        }
        if(tolower(c)>='a' && tolower(c)<='z'){
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {


    int st=0,end=s.length()-1;

    while(st<end){
        if(isAlphaNum(s[st])==false){
            st++;
            continue;
            
        }
        if(isAlphaNum(s[end])==false){
            end--;
            continue;
        }
        if(tolower(s[st])!=tolower(s[end])){
            return false;
        }
        st++,end--;
    }
    return true;
        
    }
int main()
{
    string str="racecar";
    
    
    cout<<isPalindrome(str);
}






