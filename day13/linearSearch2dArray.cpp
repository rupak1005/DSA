#include <iostream>
using namespace std;

int main(){
    int matrix[4][3]={{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    int row=4;
    int col=3;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    int target =11;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(matrix[i][j]==target){
                cout<<i+1<<','<<j+1;
            }
        }
        cout<<endl;
    }
    
    
}