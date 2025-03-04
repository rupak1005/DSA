#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Sort(vector<int>& arr,int n){
    sort(arr.begin(),arr.end());
    for(int a:arr){
        cout<<a<<" ";
    }
}


void DutchFlagSort(vector<int> &arr,int n){
    int low=0, mid=0, high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid],arr[low]);
            mid++;
            low++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else if(arr[mid]==2){
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    for(int i:arr){
        cout<<i<<" ";
    }
}

void OptimalSort(vector<int> arr,int n){
    int count0=0,count1=0,count2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){count0++;}
        else if(arr[i]==1){count1++;}
        else count2++;
    }
    int indx=0;
    for(int i=0;i<count0;i++){
        arr[indx++]=0;
        
    }
    for(int i=0;i<count1;i++){
        arr[indx++]=1;
        
    }
    for(int i=0;i<count2;i++){
        arr[indx++]=2;
    }
    
    for(int a:arr){
        cout<<a<<" ";
    }
}
int main(){
    vector<int> arr={2,0,2,1,1,0,1,2,0,0};
    int n=arr.size();
    
    // Sort(arr,n);
    cout<<endl;
    
    // OptimalSort(arr,n);
    DutchFlagSort(arr,n);
}