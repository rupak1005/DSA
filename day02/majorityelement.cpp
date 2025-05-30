#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



void majorityElement(vector<int> &vec ,int n){
    for(int i=0;i<n;i++){
        int freq=1;
        for(int j=i+1;j<n;j++){
            if(vec[i]==vec[j]){
                freq++;
            }
        }
        if(freq>n/2){
            cout<<vec[i];
        }
    }
}



int majorityElementOP(vector<int> &vec, int n) {
    sort(vec.begin(), vec.end());
    int freq = 1;
    int ans = vec[0];

    for (int i = 1; i < n; i++) {
        if (vec[i] == vec[i - 1]) {
            freq++;
        } else {
            freq = 1; // Reset frequency count for the new element
        }
        if (freq > n / 2) {
            cout<<vec[i]; // Return majority element if found
        }
    }
    return -1; // Return -1 if no majority element exists
}


int mooreAlgo(vector<int> &vec, int n) {
    int freq = 0, ans = 0;

    // Phase 1: Find a candidate for the majority element
    for (int i = 0; i < n; i++) {
        if (freq == 0) {
            ans = vec[i];
        }
        if (vec[i] == ans) {
            freq++;
        } else {
            freq--;
        }
    }

    // Phase 2: Verify the candidate
    freq = 0;
    for (int i = 0; i < n; i++) {
        if (vec[i] == ans) {
            freq++;
        }
    }

    if (freq > n / 2) {
        return ans;
    }

    return -1; // Return -1 if no majority element exists
}


int main()
{
    vector<int> vec={ 9,9,9,9,1,2,2};
    int n=vec.size();


    // majorityElement(vec,n);
    // majorityElementOP(vec,n);
    mooreAlgo(vec,n);

    
    
}
