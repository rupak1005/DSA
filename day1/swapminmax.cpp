#include <iostream>
using namespace std;

void swapMinMax(int arr[], int size) {
    int minIndex = 0, maxIndex = 0;

    // Find indices of minimum and maximum elements
    for(int i=0;i<size;i++){
        if(arr[i]<arr[minIndex])
        {
            minIndex=i;
        }
        if(arr[i]>arr[maxIndex])
        {
            maxIndex=i;
        }
    }
    // Swap the minimum and maximum elements
    int temp =arr[minIndex];
    arr[minIndex]=arr[maxIndex];
    arr[maxIndex]=temp;
    
}

int main() {
    int nums[] = {5, 15, 22, 1, -15, 24};
    int size = sizeof(nums) / sizeof(nums[0]);

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    swapMinMax(nums, size);

    cout << "Array after swapping min and max: ";
    for (int i = 0; i < size; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
