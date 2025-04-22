class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        int lcs=1;
        int ccs=1;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                continue;
            }
            else if(nums[i]==nums[i-1]+1){
                ccs++;
                
            }else{
            lcs=max(ccs,lcs);
            ccs=1;}

        }
        return max(lcs,ccs);

    }
};