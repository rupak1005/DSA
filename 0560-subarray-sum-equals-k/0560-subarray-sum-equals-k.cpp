class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> m;
        m[0]=1;
        int count=0;
        int prefixSum=0;
        for(int i=0;i<n;i++){
            prefixSum+=nums[i];
            int val=prefixSum-k;
            if(m.find(val)!=m.end()){
                count+=m[val];
            }
            m[prefixSum]++;

        }
        return count;
    }
};