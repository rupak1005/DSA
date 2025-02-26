#include <iostream>
using namespace std;



int maxRowSum(int matrix[][3],int row ,int col){
    int maxrowsum=0;
    for(int i=0;i<row;i++){
        int maxrowsumI=0;
        for(int j=0;j<col;j++){
            maxrowsumI+=matrix[i][j];
            
        }
         maxrowsum=max(maxrowsum,maxrowsumI);
    }
    return maxrowsum;
}

int main(){
    int matrix[4][3]={{1,20,30},{4,5,6},{7,8,9},{10,11,12}};
    int row=4;
    int col=3;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    int ans=maxRowSum(matrix,row,col);
    cout<<ans;
    
}