#include <iostream>
#include <vector>
using namespace std;

void printSubset(vector<int> &arr,vector<int> &ans,int i){
    if(i==arr.size()){
        for(int a:ans){
            cout<<a<<" ";
            
        }
        cout<<endl;
        return;
    }
    //inclusion
    ans.push_back(arr[i]);
    printSubset(arr, ans, i+1);
      //exclustion
      
      ans.pop_back();
      printSubset(arr, ans,i+1);
}


int main(){
    vector<int> arr={1,2,3};
    vector<int> ans;
    printSubset(arr,ans,0);
    
}