#include<bits/stdc++.h>
#include <climits>
using namespace std;
int maxSubarray(vector<int> & nums){
    int maxSum=INT_MIN;
    int currSum=0;
    for(auto i:nums){
        currSum+=i;
        maxSum=max(currSum,maxSum);
        if(currSum<0){
            currSum=0;
        }
    }
    return maxSum;
    
}


int main(){
    vector<int> nums=[-2,1,-3,4,-1,2,1,-5,4];
    int n=maxSubarray(nums);
    cout<<n;
}