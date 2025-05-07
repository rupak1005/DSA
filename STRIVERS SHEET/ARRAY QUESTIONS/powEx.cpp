#include<bits/stdc++.h>
using namespace std;



double Pow(int x,int n){
    double ans=1.0;
    long long m=n;
    if(m<0)m=-1*m;
    while(m>0){
        if(m%2==1){
            ans*=x;
            m--;
        }else{
            x*=x;
            m/=2;
        }
        
    }
    if(n<0){
        ans=(double)1.0/(double)ans;
    }
    return ans;
    
}
int main(){
    
    double n=Pow(2,-2);
    cout<<n;
    
}
