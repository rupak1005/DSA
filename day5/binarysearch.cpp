#include <iostream>
using namespace std;


void binarySearch(int ar[],int n ,int key){
    int start=0;
    int end=n-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(ar[mid]>key){
            end=mid-1;
        }
        if(ar[mid]<key){
                start=mid+1;
        }
        else{
                    cout<<"Element found at index "<<mid<<endl;
                    return;
                }
            }
             cout<<"Element not found"<<endl;
        }
    
   


int main(){
    
    
    int ar[] = {1,2,3,4,5,6,7,8,9,10};;
    int n = sizeof(ar)/sizeof(ar[0]);
    
    int key = 5;
    binarySearch(ar,n,key);
} 