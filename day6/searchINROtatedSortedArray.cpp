#include<iostream>
using namespace std;
#include<vector>

int rotateArraySearch(vector<int> nums, int target, int n) {
    int start = 0;
    int end = n - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (nums[mid] == target) {
            return mid;  // Found the target
        }

        // Left side is sorted
        if (nums[start] <= nums[mid]) {
            if (nums[start] <= target && target <= nums[mid]) {
                end = mid - 1;  // Target is in the left half
            } else {
                start = mid + 1;  // Target is in the right half
            }
        }
        // Right side is sorted
        else {
            if (nums[mid] <= target && target <= nums[end]) {
                start = mid + 1;  // Target is in the right half
            } else {
                end = mid - 1;  // Target is in the left half
            }
        }
    }

    return -1;  // Target not found
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int n = nums.size();
    int result = rotateArraySearch(nums, target, n);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}
