#include<bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int> & nums,int tar){
    unordered_map<int,int> map;
    for(int i=0;i<nums.size();i++){
        int comp=tar-nums[i];
        if(map.count(comp)){
            return {map[comp],i};
        }  
        map[nums[i]]=i;
    }
    return {-1,-1};
    
}

int main(){
    vector<int> nums = {3, 2, 4};
   int target = 6;
   vector<int> sum=twoSum(nums, target);
   for(auto i:sum){
   cout<<i<<" ";}
}


// nums = [3, 2, 4], target = 6

// Iteration 1: i=0, nums[i]=3, complement=3 → not in map → store (3, 0)
// Iteration 2: i=1, nums[i]=2, complement=4 → not in map → store (2, 1)
// Iteration 3: i=2, nums[i]=4, complement=2 → found!  → return {1, 2}