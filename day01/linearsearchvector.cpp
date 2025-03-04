#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> vec={1,2,3,4,5,6,7,8};
    int target=6;
    for(int a:vec){
        if(target==a){
            cout<<"found";
        }
    }

}