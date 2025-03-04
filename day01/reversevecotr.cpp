#include<iostream>
#include<vector>
using namespace std;
void reverse(vector<int> &vec ){
    int start=0;
    int end=vec.size() -1;
    
        while(start<end){
            swap(vec[start],vec[end]);
            start++;
            end--;
        }
    

}
void Printvector(vector<int>&vec){
    for(int a:vec){
        cout<<a<<" ";
    }
}
int main(){

    vector<int> vec ={1,2,3,4,5,66,7,8,1};
    
    reverse(vec);
    Printvector(vec);
}