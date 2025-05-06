#include<bits/stdc++.h>
using namespace std;



int merge(vector<int> &nums,int low,int mid,int high){
    vector<int> temp;
    int left=low;
    int right=mid+1;
    int cnt=0;
    while(left<=mid && right<=high){
        if(nums[left]<=nums[right]){
            temp.push_back(nums[left]);
            left++;
        }else{
            temp.push_back(nums[right]);
            cnt+=(mid-left+1);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(nums[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(nums[right]);
        right++;
    }
    for(auto i:temp){
        nums[low++]=i;
    }
    return cnt;
}
int mergesort(vector<int> &nums,int low,int high){
    int mid=(low+high)/2;
    int cnt=0;
    if(low>=high)return cnt;
    cnt+=mergesort(nums,low,mid);
    cnt+=mergesort(nums,mid+1,high);
    cnt+=merge(nums,low,mid,high);
    return cnt;
}

int countInversioon(vector<int> &nums,int n){
    return mergesort(nums,0,nums.size()-1);
}
int main(){
    vector<int> nums={5,4,3,2,1};
    cout<<"cont inversions "<<countInversioon(nums,nums.size())<<endl;
    for(auto i:nums){
        cout<<i<<" ";
    }
}