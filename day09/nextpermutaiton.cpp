#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int>& A) {


        //find pivot
        int n=A.size();
        int pivot=-1;
        for(int i=n-2;i>=0;i--){
            if(A[i]<A[i+1]){
                pivot=i;
                break;
            }
        }
        if(pivot ==-1){
            reverse(A.begin(),A.end());
            return;
        }
        
    //swap with rme

    for(int i=n-1;i>pivot;i--){
        if(A[i]>A[pivot]){
            swap(A[i],A[pivot]);
            break;
        }
    }

    //reverse the last part of array
    reverse(A.begin() +pivot +1,A.end());
    }

int main(){
    vector<int> A={1,2,3,6,5,4};
    nextPermutation(A);
    for(int a:A){
        cout<<a<<" ";
    }
    
}
