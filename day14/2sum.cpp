#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums) {
  vector<vector<int>> ans;
  sort(nums.begin(), nums.end()); // Sort the array
  int n = nums.size();

  for (int i = 0; i < n; i++) {
    if (i > 0 && nums[i] == nums[i - 1])
      continue; // Skip duplicates

    int j = i + 1;
    int k = n - 1;

    while (j < k) {
      int sum = nums[i] + nums[j] + nums[k];

      if (sum < 0) {
        j++; // Move left pointer to the right to increase the sum
      } else if (sum > 0) {
        k--; // Move right pointer to the left to decrease the sum
      } else {
        ans.push_back({nums[i], nums[j], nums[k]}); // Found a triplet
        j++;
        k--;

        // Skip duplicates for the second pointer (j)
        while (j < k && nums[j] == nums[j - 1]) {
          j++;
        }

        // Skip duplicates for the third pointer (k)
        while (j < k && nums[k] == nums[k + 1]) {
          k--;
        }
      }
    }
  }

  return ans;
}

int main() {
  vector<int> nums = {-1, 0, 1, 2, -1, -4};

  vector<vector<int>> ans = threeSum(nums);
}
