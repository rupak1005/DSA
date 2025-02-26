#include <iostream>
#include <vector>

using namespace std;


void mergeSortedArray(vector<int> &A,int m,vector<int> &B,int n){//O(m+n)
    int i=m-1;
    int j=n-1;
    int index=m+n-1;
    while(i>=0 &&j>=0 ){
        if(A[i]>=B[j]){
            A[index]=A[i];
            index--;
            i--;
        }
        else{
            A[index]=B[j];
            index--;
            j--;
        }
    }
    while(j>=0){
        A[index]=B[j];
        j--;
        index--;
    }
    
    for(int a:A){ 
        cout<<a<<" ";
    }
}

int main(){
    
    vector<int> nums1={4,5,6,0,0,0};
    int m=3;
    vector<int> nums2={1,1,3};
    int n=nums2.size();
    mergeSortedArray(nums1,m,nums2,n);
}