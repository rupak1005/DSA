#include<bits/stdc++.h>
using namespace std;


bool isPalindrome(int x) {
        // string s=to_string(x);
        // reverse(s.begin(),s.end());
        // if(s==to_string(x)){
        //     return true;
        // }
        // return false;
        // 
        // 
        int original=x;
        int reversed=0;
        if(x<0){
            return false;
        }
        while(x!=0){
            int digit=x%10;
            reversed=reversed*10+digit;
            x/=10;
        }
        if(original==reversed){
            return true;
        }
        return false;
        }
        
        
int main(){
    int x=1321;
    bool n=isPalindrome(x);
    cout<<n;
}        