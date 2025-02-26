#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;  // Maps number to its index in the array
    vector<int> ans;

    // Traverse through the array
    for (int i = 0; i < nums.size(); i++) {
        int first = nums[i];  // The current number
        int second = target - first;  // The complement we need to find

        // If the complement exists in the map, we've found the solution
        if (m.find(second) != m.end()) {
            ans.push_back(i);  // Current index
            ans.push_back(m[second]);  // Index of the complement
            break;  // We found the pair, no need to continue
        }

        // If not found, store the number with its index
        m[first] = i;
    }

    return ans;  // Return the result with the indices
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    cout << "Indices: ";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}
