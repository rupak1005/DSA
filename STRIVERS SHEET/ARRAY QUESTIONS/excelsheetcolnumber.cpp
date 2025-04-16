#include<bits/stdc++.h>
using namespace std;
int titletocolnumber(string s){
    int colnum=0;
    for(auto it:s){
        colnum=colnum*26+(it-'A'+1);
    }
    return colnum;
}

int main(){
    string s="AB";
    int ans=titletocolnumber(s);
    cout<<ans;
}