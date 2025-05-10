#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    
    while (left <= mid && right <= high) {
        if (nums[left] <= nums[right]) {
            temp.push_back(nums[left++]);
        } else {
            temp.push_back(nums[right++]);
        }
    }
    while (left <= mid) temp.push_back(nums[left++]);
    while (right <= high) temp.push_back(nums[right++]);
    
    for (int i = low; i <= high; i++) {
        nums[i] = temp[i - low];
    }
}

int countpairs(vector<int> &nums, int low, int mid, int high) {
    int cnt = 0;
    int right = mid + 1;
    for (int i = low; i <= mid; i++) {
        while (right <= high && (long long)nums[i] > 2LL * nums[right]) {
            right++;
        }
        cnt += right - (mid + 1);
    }
    return cnt;
}

int countReversePairs(vector<int> &nums, int low, int high) {
    if (low >= high) return 0;
    int mid = (low + high) / 2;
    int cnt = 0;
    cnt += countReversePairs(nums, low, mid);
    cnt += countReversePairs(nums, mid + 1, high);
    cnt += countpairs(nums, low, mid, high);
    merge(nums, low, mid, high);
    return cnt;
}

int main() {
    vector<int> nums = {2, 4, 3, 5, 1};
    int n = nums.size();
    cout << countReversePairs(nums, 0, n - 1) << endl;
}
