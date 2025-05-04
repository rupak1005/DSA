#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;


vector<int> findmissingnrepeating(vector<int> &nums){
    int n=nums.size();
    unordered_map<int,int> map;
    for(auto i:nums){
        map[i]++;
    }
    int missing =-1;
    int repeating=-1;
    
   
        
    for(int i=1;i<n;i++){
        if(map[i]>=2)repeating=i;
        if(map[i]==0)missing=i;
        if(repeating!=-1 && missing !=-1)break;
    }
    return {repeating,missing};
}

int main(){
    vector<int> nums={1,2,3,3,5};
    vector<int> ans=findmissingnrepeating(nums);
    cout<<"Missing number is "<<ans[0]<<" and repeating number is "<<ans[1]<<endl;
    
}