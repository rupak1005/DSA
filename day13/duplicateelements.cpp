#include <iostream>
#include <vector>
using namespace std;


int findDuplicate(vector<int>& arr) {
    int slow=arr[0];
    int fast=arr[0];
    do{
        slow=arr[slow];  //+1
        fast=arr[arr[fast]]; //+2
    }
    while(slow!=fast);
    
    slow=arr[0];
    while(slow!=fast){
        slow=arr[slow]; 
        fast=arr[fast]; 
        
        
    }
    return slow;
    
        
    }
int main(){
    
    
    vector<int> arr={1,3,4,2,2};
    cout<<findDuplicate(arr);
    
}