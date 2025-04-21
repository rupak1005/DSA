#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto i:s){
            if(i=='(' || i=='{'||i=='['){//opening
                st.push(i);
            }else{
                if(st.empty()!=0){
                    return false;
                }
                if(st.top()=='(' && i==')' ||st.top()=='{' && i=='}' ||st.top()=='[' && i==']' ){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        return st.size()==0;
        
    }
};