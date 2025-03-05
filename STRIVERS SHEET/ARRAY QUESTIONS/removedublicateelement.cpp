#include <iostream>
#include <vector>
#include <set>
using namespace std;

//bruteforce

int removeDuplicates(vector<int> &arr,int n ){
    set<int> s;
    for(int i=0;i<n;i++){
        s.insert(arr[i]);
        
    }
    int k=s.size();
    int j=0;
    for(int x:s){
        arr[j++]=x;
    }
    return k;
}


// optimal

int removeDuplicates2(vector<int> &arr,int n){
    int i=0;
    for(int j=1;j<n;j++){
        if(arr[i]!=arr[j]){
            i++;
            arr[i]=arr[j];
        }
    }
    return i+1;
    
}

int main(){
    vector<int> arr = {1,1,2,2,2,3,3};
      int n = sizeof(arr)/sizeof(arr[0]);
      int k = removeDuplicates2(arr, n);
      cout << "The array after removing duplicate elements is " << endl;
      for (int i = 0; i < k; i++) {
        cout << arr[i] << " ";
      }
}
