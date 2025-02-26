#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> ans;
    
    // Sort the array to facilitate the two-pointer approach
    sort(nums.begin(), nums.end());
    
    // Iterate through the array with the first index (i)
    for (int i = 0; i < n - 3; ++i) {
        // Skip duplicate elements for the first index
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        
        // Iterate with the second index (j)
        for (int j = i + 1; j < n - 2; ++j) {
            // Skip duplicate elements for the second index
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            
            // Use two pointers (p, q) for the third and fourth elements
            int p = j + 1;
            int q = n - 1;
            
            while (p < q) {
                // Calculate the sum of the four elements
                long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[p] + (long long)nums[q];
                
                if (sum < target) {
                    // If sum is smaller than target, move the left pointer right to increase the sum
                    p++;
                } else if (sum > target) {
                    // If sum is larger than target, move the right pointer left to decrease the sum
                    q--;
                } else {
                    // Found a valid quadruplet
                    ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                    
                    // Move both pointers inward while skipping duplicates
                    p++;
                    q--;
                    
                    // Skip duplicates for the third element (p)
                    while (p < q && nums[p] == nums[p - 1]) {
                        p++;
                    }
                    
                    // Skip duplicates for the fourth element (q)
                    while (p < q && nums[q] == nums[q + 1]) {
                        q--;
                    }
                }
            }
        }
    }
    
    return ans;
}

