#include <iostream>
#include <vector>
using namespace std;


int partition(vector<int> &arr,int st,int end){
    
    int idx=st-1;
    int pivot=arr[end];
    
    for(int j=st;j<end;j++){
        if(arr[j]<=pivot){
            idx++;
            swap(arr[j],arr[idx]);
        }
        
        
    }
    idx++;
    swap(arr[idx],arr[end]);
    return idx;
}

void quickSort(vector<int> &arr,int st,int end){
    if(st<end){
        int pivot=partition(arr,st,end);
        
        //left 
        quickSort(arr, st,pivot-1);
        
        //right
        
        quickSort(arr, pivot +1, end);
    }
    
}

int main(){
    vector<int> arr={1,3,4,2,6,7,5};
    
    quickSort(arr,0,arr.size()-1);
    for(int i:arr){
        cout<<i<<" ";
        
    }
    
}