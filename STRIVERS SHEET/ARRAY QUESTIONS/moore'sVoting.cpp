#include<bits/stdc++.h>
using namespace std;

int majorityelement(vector<int>&nums){
    int cnt=0;
    int el;
    for(auto i:nums){
        if(cnt==0){
            cnt=1;
            el=i;
        }else if(i==el){
            cnt++;
        }else{
            cnt--;
        }
    }
    cnt=0;
    for(auto i:nums){
        if(i==el){
            cnt++;
        }
    }
    if(cnt>nums.size()/2){
        return el;
    }
    return -1;
}
int main(){
    vector<int> nums={1,2,3,5,5,5,5,5};
    int n=majorityelement(nums);
    cout<<n;
}