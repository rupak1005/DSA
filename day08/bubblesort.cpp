#include<iostream>

using namespace std;

int main(){
    
    int a[]={5,4,3,2,1};
    int n=5;
    for(int i=0;i<n-1;i++){
        bool isSwapped=false;
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                isSwapped=true;
            }
        }
        if(!isSwapped){
            break;
        }  
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}