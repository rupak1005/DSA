#include <iostream>
using namespace std;


int diagonalSum(int matrix[][3],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                sum+=matrix[i][j];
            }
            else if(j==n-1-i){
                sum+=matrix[i][j];
            }
        }
    }
    return sum;
}
int main(){
    int matrix[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int n=3;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<diagonalSum(matrix, 3);
    
    
}