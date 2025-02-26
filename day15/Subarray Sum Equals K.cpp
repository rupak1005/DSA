int subarraySum(vector<int>& arr, int k) {
    int n = arr.size();
    int count = 0;
    
    // Use a hash map to store the frequency of prefix sums.
    unordered_map<int, int> m;
    
    // Initialize the prefix sum and count the occurrences of prefix sum 0.
    int prefixSum = 0;
    m[0] = 1;  // to handle the case when the subarray itself is equal to k

    // Traverse the array to calculate the prefix sum.
    for (int j = 0; j < n; j++) {
        // Update the prefix sum with the current element.
        prefixSum += arr[j];

        // Check if there's a subarray whose sum equals k.
        int val = prefixSum - k;
        if (m.find(val) != m.end()) {
            count += m[val];
        }

        // Record the frequency of the current prefix sum.
        m[prefixSum]++;
    }

    return count;
}
