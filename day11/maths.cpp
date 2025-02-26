#include <cmath>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int isPrime(int n){
    
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
        
    }
    return true;
}


int countPrime(int n){
    vector<bool> isPrime(n+1,true);
    int count=0;
    
    for(int i=2;i<=n;i++){
        if(isPrime[i]){
            count++;
            for(int j=i*2;j<n;j=j+i){
                isPrime[j]=false;
            }
        }
        
    }
    return count ; 
}
void printPrime(int n){
    
    for(int i=2;i<=n;i++){
        if(isPrime(i)){
            cout<<i<<" ";
        }
    }
}
void digit(int n){
    int count=0;
    while(n!=0){
        int digit=n%10;
        count++;
        n=n/10;
    }
    cout<<count;
}

bool isArmstrong(int n){
    int copyN=n;
    int sumofCubes=0;
    while(n!=0){
        
        int digit=n%10;
        sumofCubes+=(digit*digit*digit);
        n=n/10;
        
    }
    if(sumofCubes==copyN){
        return true;
    }
    return false;
}

int GCD(int a,int b){
    int gcd=1;
    
    if(a==0 || b==0){
        gcd=max(a,b);
    }
    for(int i=1;i<=min(a,b);i++){
    if(a%i==0 && b%i==0){
        gcd=i;
    }
}return gcd;
}


int GCDeuc(int a ,int b){
    while(a>0 && b>0){
        if(a>b){
            a=a%b;
        }else{
            b=b%a;
        }
    }
    if(a==0) {return b;}
  return a;
    
    
}


int gcdrec(int a,int b){
    if(b==0) return a;
    return gcdrec(b, a%b);
}
int main(){
    
    int n=153;
    // cout<<countPrime(47);
    
    // digit(n);
    // cout<<(int)(log10(n)+1)<<endl;
    // 
    // cout<<isArmstrong(n);
    // 
    // cout<<GCDeuc(20,28);
    cout<<gcdrec(0,28);
}