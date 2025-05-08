#include<bits/stdc++.h>
using namespace std;
    

int griduniquepath(int i,int j,int n,int m){
    if(i==n-1 && j==m-1)return 1;
    if(i>n-1 || j>m-1 )return 0;
    else return griduniquepath(i+1,j,n,m)+griduniquepath(i,j+1,n,m);
    
}

int main(){
    cout<<griduniquepath(0, 0, 2, 2);
    
    
}