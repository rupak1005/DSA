#include<bits/stdc++.h>
using namespace std;
vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        
        int cnt1 = 0, cnt2 = 0;
        int el1 = 0, el2 = 1;  // initialize to different values
        
        for (auto i : nums) {
            if (el1 == i) cnt1++;
            else if (el2 == i) cnt2++;
            else if (cnt1 == 0) {
                el1 = i;
                cnt1 = 1;
            } else if (cnt2 == 0) {
                el2 = i;
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        
        // Verify counts
        cnt1 = cnt2 = 0;
        for (auto i : nums) {
            if (i == el1) cnt1++;
            else if (i == el2) cnt2++;
        }
        
        if (cnt1 > n / 3) ans.push_back(el1);
        if (cnt2 > n / 3 && el2 != el1) ans.push_back(el2);
        sort(ans.begin(),ans.end());
        return ans;
    }
    

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
    vector<int> nums={1,2};
    vector<int> ans=majorityElement(nums);
    for(auto i:ans){
        cout<<i<<" ";
    }
}