#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    unordered_set<int> s;
    int n = grid.size();
    int a = -1, b = -1;
    vector<int> ans;
    int actSum = 0;
    int expSum = (n * n * (n * n + 1)) / 2;  // Corrected formula to calculate the sum from 1 to n^2.

    // Traverse the grid to find the repeated number and the actual sum
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            actSum += grid[i][j];  // Add to the actual sum
            if (s.find(grid[i][j]) != s.end()) {  // Check if the number is repeated
                a = grid[i][j];
                ans.push_back(a);  // Store the repeated number
            }
            s.insert(grid[i][j]);  // Insert the number into the set
        }
    }

    // Find the missing number using the formula
    b = actSum - a - expSum;  
    ans.push_back(b);  // Store the missing number

    return ans;
}

int main() {
    vector<vector<int>> grid = {
        {1, 2, 3},
        {4, 5, 6},
        {6, 8, 9}
    };

    vector<int> result = findMissingAndRepeatedValues(grid);
    cout << "Repeated: " << result[0] << ", Missing: " << result[1] << endl;

    return 0;
}
