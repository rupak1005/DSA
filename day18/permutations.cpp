#include <vector>
#include <algorithm>  // for swap
using namespace std;

void getperms(vector<int>& nums, int idx, vector<vector<int>>& ans) {
    if (idx == nums.size()) {
        ans.push_back(nums);  // Push nums directly
        return;
    }

    for (int i = idx; i < nums.size(); i++) {
        swap(nums[i], nums[idx]);
        getperms(nums, idx + 1, ans);
        swap(nums[i], nums[idx]);  // Backtrack
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    getperms(nums, 0, ans);
    return ans;
}
