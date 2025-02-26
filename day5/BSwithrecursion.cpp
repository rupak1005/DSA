#include <iostream>
using namespace std;



int binarySearch(int arr[],int target,int start,int end){
    while(start<=end){
    int mid=start+(end-start)/2;
    if(target>arr[mid]){
        return binarySearch(arr,target,mid+1,end);//second half
    }
    else if(target<arr[mid]){
        return binarySearch(arr,target,start,mid-1);//first half
    }
    else{
        return mid;
    }}
    return -1;
}

int main(){
    int arr[]={-1,0,3,5,9,12};//sorted array even
int n=6;
int target=9;
int start=0;
int end=n-1;
int ans=binarySearch(arr,target,start,end);
cout<<ans;
}
//time complexity:O(logn)