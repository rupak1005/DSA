#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


bool isPalin(string &part){
    string s2=part;
    reverse(s2.begin(),s2.end());
    return part==s2;
}
void getPalindrome(string s, vector<vector<string>> &ans,vector<string> partitions){
    
    
    if(s.size()==0){
        ans.push_back(partitions);
        return;
    }
    for(int i=0;i<s.size();i++){
        string part=s.substr(0,i+1);
        
    
    
    if(isPalin(part)){
        partitions.push_back(part);
        getPalindrome(s.substr(i+1), ans, partitions);
        partitions.pop_back();
        
    }
    
    }
}


vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> partitions;

    getPalindrome(s,ans,partitions);
    return ans;
    
}
int main(){
    
    string s = "aab";
    vector<vector<string>> ans=partition(s);
    for(auto i:ans){
        for(string s:i){
            cout<<s<<" ";
        }
        cout<<endl;
    }
    
    
}