#include <algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int searchinsertpos(vector<int> arr,int target){
    int s=0;
    int e=arr.size()-1;
    int ans=arr.size();
    while(s<=e){
        int mid=s+(e-s)/2;
        
        if(arr[mid]>=target){
           ans=mid;
           e=mid-1;
            
            
        }else{
            s=mid+1;
        }
    }
    return s;
}

int main(){
    vector<int> nums = {1,3,5,5,5,5,6};
    int target = 5;
    int pos=searchinsertpos(nums,target);
    // int pos=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
    int pos1=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
    cout<<pos;
}