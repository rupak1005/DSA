#include<bits/stdc++.h>
using namespace std;

int countprime(int n){
    if(n<=1) return 0;
    vector<int> isPrime(n+1,1);
    isPrime[0]=isPrime[1]=0;
    for(int i=2;i*i<n;i++){
        if(isPrime[i]){
            for(int j=i*i;j<n;j+=i){
                isPrime[j]=0;
            }
        }
    }
    int count=0;
    for(int i=2;i<n;i++){
        if(isPrime[i]){
            count++;
        }
    }
    return count;
}
int main(){
    int n;
    cin>>n;
    n=countprime(n);
    cout<<n;
}