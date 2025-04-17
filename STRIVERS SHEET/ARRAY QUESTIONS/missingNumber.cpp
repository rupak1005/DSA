class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<=n;i++){
            sum+=i;
        }
        int sumarray=0;
        for(auto i:nums){
            sumarray+=i;
        }
        return sum-sumarray;
    }
};