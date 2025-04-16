#include<bits/stdc++.h>
#include<vector>
using namespace std;


int smallestkth(vector<vector<int>> matrix,int k){
    vector<int> x;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            x.push_back(matrix[i][j]);
        }
        sort(x.begin(),x.end());
        
    }
    return x[k-1];
}
int main(){
    vector<vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};
   int k = 8;
   cout<<smallestkth(matrix,k);
}