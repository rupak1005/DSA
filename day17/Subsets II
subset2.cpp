class Solution {
public:




    void getAllSub(vector<int>& nums,vector<int>& ans,int i,vector<vector<int>> &allSet){
        sort(nums.begin(),nums.end());
        if(i==nums.size()){
            allSet.push_back({ans});
            return;
        }

        //inclution
        ans.push_back(nums[i]);
        getAllSub(nums,ans,i+1,allSet);

        // exclution
        ans.pop_back();
        int idx=i+1;
        while(idx<nums.size() && nums[idx]==nums[idx-1]){
            idx++;
        }
        getAllSub(nums,ans,idx,allSet);



    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> allSet;
        vector<int> ans;

        getAllSub(nums,ans,0,allSet);
        return allSet;

        
        
    }
};