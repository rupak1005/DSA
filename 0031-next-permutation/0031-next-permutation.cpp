class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int arr[n];
        int j=0;
        for(auto i:nums){
            arr[j++]=i;

        }
        
        next_permutation(arr,arr+n);
        j=0;
        for(auto i:arr){
            nums[j++]=i;
        }
        
        
    }
};