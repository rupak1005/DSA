#include<iostream>
using namespace std;

double myPow(double x, int n) {
        if(n<0){
            x=1/x;
            n=-n;
        }
        double ans=1;
        while(n>0){
            if(n%2==1){
                ans*=x;
            }
            x*=x;
            n/=2;
        }
        return ans;
    }

int main(){
    double x=2;
    int n=10;
    double ans=myPow(x,n);
    cout<<ans;
    
}
