#include <iostream>
#include <string>
using namespace std;



bool isFreqSame(int freq1[],int freq2[]){
    for(int i=0;i<26;i++){
        if(freq1[i]!=freq2[i]){
            return false;
        }
    }
    return true;
}
bool checkInclusion(string s1, string s2) {
    
    int freq[26]={0};
    for(int i=0;i<s1.length();i++){
        freq[s1[i]-'a']++;
    }
    for(int i=0;i<s2.length();i++){
        int windidx=0,idx=i;
        int windFreq[26]={0};
        while(windidx<s1.length() && idx<s2.length()){
            windFreq[s2[idx]-'a']++;
            windidx++,idx++;
        }

        if(isFreqSame(freq,windFreq)){
            return true;
        }
    }
    return false;
}


int main(){
    
    string s1 = "ab", s2 = "eidbaooo";
    cout<<checkInclusion(s1,s2);
    
    
    
}