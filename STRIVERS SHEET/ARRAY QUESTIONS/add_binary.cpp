#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
#include<string>

using namespace std;



 string addbinary(string str1,string str2){
     string ans="";
     int carry=0;
     int i=str1.size()-1;
     int j=str2.size()-1;
     while(i>=0||j>=0||carry){
         if(i>=0)carry+=str1[i]-'0';
         if(j>=0)carry+=str2[j]-'0';
         ans+=carry%2+'0';
            carry/=2;
            i--;
            j--;
     }
     reverse(ans.begin(),ans.end());
     return ans;
 }
int main(){
    string  str1="100";
    string str2="110";
    string str=addbinary(str1,str2);
    cout<<str;
}