#include <iostream>
using namespace std;

void printUniqueValues(int arr[], int size) {
    bool isUnique;
    for(int i=0;i<size;i++)
    {
        isUnique=true;
        for(int j=0;j<size;j++)
        {
            if(i!=j && arr[i]==arr[j])
            {
                isUnique=false;
                break;
            }
        }
        if(isUnique)
        {
            cout<<arr[i]<<" ";

        }

    }
   
}

int main() {
    int nums[] = {4, 5, 7, 4, 8, 5, 9, 10};
    int size = sizeof(nums) / sizeof(nums[0]);

    printUniqueValues(nums, size);

    return 0;
}
