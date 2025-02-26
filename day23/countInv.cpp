
#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int> &arr,int st,int mid,int end){
    
    vector<int> temp;
    int i=st,j=mid+1;
    int Invcount=0;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
            Invcount=mid-i+1;
        }
        
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
        
    }
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
        
    }
    for(int idx=0;idx<temp.size();idx++){
        arr[idx+st]=temp[idx];
    }
    return Invcount;
}
int mergeSort(vector<int> &arr,int st,int end){
    if(st<end){
        int mid=st+(end-st)/2;
        
        
        //left
        int leftInv=mergeSort(arr, st, mid);
        
        //right
       int rightInv= mergeSort(arr, mid+1, end);
        
        int Inv=merge(arr,st,mid,end);
        return leftInv+rightInv+Inv;
    }
    return 0;
    
}

int main(){
    vector<int> arr={6,3,5,2,7};
    
    cout<<mergeSort(arr,0,arr.size()-1);
   
}