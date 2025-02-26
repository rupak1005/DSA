#include <climits>
#include <iostream>
using namespace std;
int main(){
    int n=4537;
    int revInt=0;
    while(n!=0){
        int dig=n%10;
        if(revInt>INT_MAX/10 || revInt<INT_MIN/10){
            cout<<0;
        }
        revInt=revInt*10+dig;
        n=n/10;
        
        
    }
    cout<<revInt;
}