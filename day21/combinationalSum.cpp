#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


set<vector<int>> s;
void helper(vector<int> & arr,int i,int tar,vector<int> &combin,vector<vector<int>> &ans){
    
    
    
    
    //base case
    
    if(i==arr.size()||tar<0){
        return;
    }
    
    
    
    if(tar==0){
        if(s.find(combin)==s.end()){
            ans.push_back(combin);
            s.insert(combin);
            
            
        }
        
        
    }
    //single
    
    combin.push_back(arr[i]);
    
    helper(arr,i+1,tar-arr[i],combin,ans);
    
    //multiple
    helper(arr,i,tar-arr[i],combin,ans);
    
    //exclution
    
    combin.pop_back();
    
    helper(arr,i+1,tar,combin,ans);
    
}


vector<vector<int>> combinationalSum(vector<int> & candidates,int target){
    vector<int> combin;
    vector<vector<int>> ans;
    helper(candidates,0,target,combin,ans);
    return ans;
    
    
}
int main(){
    vector<int> candidates={2,3,6,7};
    int target=8;
    vector<vector<int>> ans=combinationalSum(candidates,target);
    for(auto i:ans){
        for(int num:i){
            
            cout<<num<<" ";
        }
        cout<<endl;
    }
    
    
    
    
}