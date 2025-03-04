#include<iostream>
#include<vector>
using namespace std;





//optimal
vector<int> pairSumOP(vector<int>&nums,int target){
    vector<int> ans;
    int n=nums.size();
    int i=0;int j=n-1;
    while(i<j){
        if(nums[i]+nums[j]>target){
            j--;

        }
        else if(nums[i]+nums[j]<target){
            i++;

        }
        else{
            ans.push_back(i);
            ans.push_back(j);
            return ans;


        }
    }
    return ans;

}


//bruteforce
vector<int> pairSum(vector<int> &nums, int target) {
    vector<int> ans;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans; // Return empty if no pair found
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 26;
    // vector<int> ans = pairSum(nums, target);
    vector<int> ans = pairSumOP(nums, target);

    if (ans.size() == 2) {
        cout << ans[0] << " , " << ans[1] << endl;
    } else {
        cout << "No pair found." << endl;
    }

    return 0;
}
