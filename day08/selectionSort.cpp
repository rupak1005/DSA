#include<iostream>

using namespace std;


void selectionSort(int a[],int n){
    for(int i=0;i<n-1;i++){
    int minIndex=i;
    for(int j=i+1;j<n;j++){
        if(a[j]<a[minIndex]){
            minIndex=j;
        }
        
    }swap(a[i],a[minIndex]);
}
for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
}
}


int main(){
    
    int a[]={5,4,3,2,1};
    int n=5;
    selectionSort(a,n);
    
    

}