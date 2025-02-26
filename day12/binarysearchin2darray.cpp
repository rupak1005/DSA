#include <iostream>
#include <vector>
using namespace std;


int searchinRow(vector<vector<int>> &matrix,int target,int row,int n){
    int start=0;
    int end=n-1;
    while(start<=end){
        int mid=start+(end-start/2);
        if(target==matrix[row][mid]){
            return true;
        }
        else if(target>matrix[row][mid]){
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
    return false;
}


int binarysearch(vector<vector<int>> &matrix,int target){
    int m=matrix.size();
    int n=matrix[0].size();
    int start=0;
    int end=m-1;
    while(start<=end){
        int midRow=start+(end-start)/2;
        if(target>=matrix[midRow][0] && target<=matrix[midRow][n-1]){
            return searchinRow(matrix,target,midRow,n);
        }
        else if(target>matrix[midRow][n-1]){
            start=midRow+1;
        }
        else{
            end=midRow-1;
        }
    }
    return false;
}

int main(){
    
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int  target = 11;
    cout<<binarysearch(matrix,target);
    
}