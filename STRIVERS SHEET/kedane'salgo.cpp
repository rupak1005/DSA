
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

void maxSubarray(vector<int> nums){
    int maxsum=INT_MIN;
    int currsum=0;
    int n=nums.size();
    int s=0;
    int e=0;
    int tempstart=0;
    
    for(int i=0;i<n;i++){
        currsum+=nums[i];
        if(currsum>maxsum){
            maxsum=currsum;
            s=tempstart;
            e=i;
        }
        if(currsum<0){
            currsum=0;
            tempstart=i+1;
        }
        
    }
    for(int i=s;i<=e;i++){
        cout<<nums[i]<<" ";
    }
}
int main(){
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    maxSubarray(nums);
    
    return 0;
}
