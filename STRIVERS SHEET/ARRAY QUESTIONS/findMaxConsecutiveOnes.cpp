class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxcon=0;
        int currcon=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]){
                currcon+=1;
            }else{
                currcon=0;
            }
            maxcon=max(maxcon,currcon);
        }
        return maxcon;
    }
};