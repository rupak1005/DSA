#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int nums[] = {5, 15, 22, 1, -15, 24};
    int size = sizeof(nums) / sizeof(int);

    int min = __INT_MAX__;
    int max = -1;
    int minIndex = -1;
    int maxIndex = -1;

    for (int i = 0; i < size; i++) {
        if (nums[i] < min) {
            min = nums[i];
            minIndex = i;
        }
        if (nums[i] > max) {
            max = nums[i];
            maxIndex = i;
        }
    }

    cout << "Minimum element: " << min << endl;
    cout << "Index of minimum element: " << minIndex << endl;
    cout << "Maximum element: " << max << endl;
    cout << "Index of maximum element: " << maxIndex << endl;

    return 0;
}
