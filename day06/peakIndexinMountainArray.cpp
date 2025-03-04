#include<iostream>

using namespace std;

#include<vector>

int peakIndex(vector<int> A){
    int start=1;
    int end=A.size()-2;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(A[mid-1]<A[mid]&&A[mid]>A[mid+1]){
            return mid;
        }
        if(A[mid-1]<A[mid]){//right
            start=mid+1;
        }
        else{//left
            end=mid-1;
        }
    }
    return -1;

}

int main(){
    vector<int> A={0,3,8,9,5,2};
    int ans=peakIndex(A);
    cout<<ans;
}