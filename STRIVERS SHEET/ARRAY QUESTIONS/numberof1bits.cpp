#include<bits/stdc++.h>
using namespace std;

int setbits(int n){
    int set=0;
    while(n){
        if(n&1){
            set++;
        }
        n=n>>1;
    }
    return set;
}
int main(){
    int n=128;
    int set=setbits(n);
    cout<<set;
}