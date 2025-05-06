#include <bits/stdc++.h>
using namespace std;

bool validparenthesis(string str) {
    stack<char> st; 
    for (auto i : str) {
        if (i == '(' || i == '{' || i == '[') {
            st.push(i);
        } 
        else if (i == ')' || i == '}' || i == ']') {
            if (st.empty()) return false; // no matching opening
            if ((i == ')' && st.top() != '(') ||
                (i == ']' && st.top() != '[') ||
                (i == '}' && st.top() != '{')) {
                return false; // mismatch
            }
            st.pop();
        }
    }
    return st.empty(); // valid if stack empty
}

int main() {
    string str = "(1+2){}[";
    bool valid = validparenthesis(str);
    cout << valid << endl; // prints 0 or 1
    return 0;
}
