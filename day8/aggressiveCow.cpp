#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;




bool isPossible(vector<int> arr,int N ,int C,int minAllowedDistance){//o(n)

int cows=1;int lastPlacedCow=arr[0];


for(int i=1;i<N;i++){//o(n)
    if(arr[i]-lastPlacedCow>=minAllowedDistance){
        cows++;
        lastPlacedCow=arr[i];
        if(cows==C){
            return true;
        }
    }
    
}
return false;
}

int getDistance(vector<int >arr,int N,int C){ //o(nlogn)
    
    sort(arr.begin(),arr.end());
    
    
    
    int start=0;
    int end=arr[N-1]-arr[0];
    int ans=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(isPossible(arr,N,C,mid)){
            ans=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        
    }
    return ans;
}


int main(){
    
    int N=5;
    int C=3;
    vector<int> arr={1,2,8,4,9};
    cout<<getDistance(arr,N,C)<<endl;//o(nlogn)
    
    return 0;
}