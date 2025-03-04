#include <iostream>
using namespace std;

void calculateSumAndProduct(int arr[], int size, int &sum, int &product) {
    sum = 0;
    product = 1;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
        product *= arr[i];
    }
}

int main() {
    int nums[] = {1, 2, 3, 4, 5};
    int size = sizeof(nums) / sizeof(nums[0]);

    int sum = 0, product = 0;

    calculateSumAndProduct(nums, size, sum, product);

    cout << "Sum of array elements: " << sum << endl;
    cout << "Product of array elements: " << product << endl;

    return 0;
}
