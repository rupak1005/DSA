#include<iostream>
#include<vector>
using namespace std;
vector<int> productofarray(vector<int> &nums,int n){
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        int product=1;
        for(int j=0;j<n;j++){
            if(i!=j){
                product*=nums[j];
            }

        }
        ans[i]=product;
    }
    return ans;
}
vector<int> productofarrayOP(vector<int> &nums,int n){
    // vector<int> prefix(n,1);
    // vector<int> suffix(n,1);
    vector<int>ans(n,1);

    // int prefix[0]=1;
    int prefix=1;
    for(int i=1;i<n;i++){
        // prefix[i]=prefix[i-1]*nums[i-1];
        prefix*=nums[i-1];
        ans[i]*=prefix;
        
        

    }

    int suffix=1;
    for(int i=n-2;i>=0;i--){
        // suffix[i]=suffix[i+1]*nums[i+1];
        suffix *= nums[i+1];
        ans[i]*= suffix;
    }

    for(int i=0;i<n;i++){
        // ans[i]=prefix[i]*suffix[i];

    }

    return ans;
    

}

int main(){
    vector<int> nums={1,2,3,4};
    int n=nums.size();

    vector<int> ans=productofarray(nums,n);
    vector<int> ans1=productofarrayOP(nums,n);
    for(int a:ans){
        cout<<a<<" ";
    }
    cout<<endl;
    for(int a:ans1){
        cout<<a<<" ";
    }
}