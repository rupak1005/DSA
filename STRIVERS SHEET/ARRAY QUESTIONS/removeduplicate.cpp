#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(int arr[],int n){
    set<int> s;
    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }
    int k=s.size();
    int i=0;
    for(auto it: s){
        arr[i]=it;
        i++;
    }
    return k;
    
}




int main() {
  int arr[] = {1,1,2,2,2,3,3};
  int n = sizeof(arr)/sizeof(arr[0]);
  int k = removeDuplicates(arr, n);
  cout << "The array after removing duplicate elements is " << endl;
  for (int i = 0; i < k; i++) {
    cout << arr[i] << " ";
  }}