// C++ Program to find the maximum subarray sum using nested loops 

#include <bits/stdc++.h>
using namespace std;


int KedaneAlgo(vector<int>& arr){
    int maxSum=INT_MIN;
    int currSum=0;
    for(int i=0;i<arr.size();i++){
        currSum+=arr[i];
        maxSum=max(maxSum,currSum);
        if(currSum<0){
            currSum=0;
        }
    }
    return maxSum;
}



int maxSubarraySum(vector<int> &arr)


{
int maxSum=INT_MIN;

for(int start=0;start<arr.size();start++)
{
    int currSum=0;
    for(int end=start;end<arr.size();end++){
        currSum+=arr[end];
        maxSum=max(currSum,maxSum);
    }
    
}
return maxSum;

}
int main() {
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    cout << maxSubarraySum(arr)<<endl;
    cout<<KedaneAlgo(arr)<<endl;
    return 0;
}