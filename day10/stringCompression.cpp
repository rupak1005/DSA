#include <iostream>
#include <string>
// #include <algorithms>
#include <vector>
#include <math.h>
using namespace std;



int compress(vector<char> &chars){
    
    int n=chars.size();
    int idx=0;
    
    for(int i=0;i<n;i++){
        int count=0;
        char ch=chars[i];
        while(i<n && chars[i]==ch){
            count++;
            i++;
        }
        if(count==1){
            chars[idx++]=ch;
        }
        else{
            chars[idx++]=ch;
            string str=to_string(count);
            for(char ch:str){
                chars[idx++]=ch;
                
            }
            
           
        }
         i--;
        
    }
    chars.resize(idx);
    return idx;
    
    
}

int main(){
    
    vector<char> chars = {'a','a','b','b','c','c','c'};
    cout<<compress(chars);
    cout<<endl;
    for(char ch:chars){
        cout<<ch<<" ";
    }
}
