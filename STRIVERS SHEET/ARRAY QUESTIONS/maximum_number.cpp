#include<bits/stdc++.h>
using namespace std;

static bool compare(string a,string b){
    return a+b>b+a;
}

string maximumNumber(vector<int> &nums){
    vector<string> str;
    for(auto it : nums){
        str.push_back(to_string(it));
    }
    sort(str.begin(),str.end(),compare);
    if(str[0]=="0")return "0";
    
    string ans="";
    for(auto it:str){
        ans+=it;
    }
    return ans;
    
    
}

int main(){
    vector<int> nums={3,30,34,5,9};
    string ans=maximumNumber(nums);
    cout<<ans;
}