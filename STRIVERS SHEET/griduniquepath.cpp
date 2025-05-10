#include<bits/stdc++.h>
using namespace std;
    
//recursion
int griduniquepath(int i,int j,int n,int m){
    if(i==n-1 && j==m-1)return 1;
    if(i>n-1 || j>m-1 )return 0;
    else return griduniquepath(i+1,j,n,m)+griduniquepath(i,j+1,n,m);
    
}





//dp

int gridUniquepath(int i,int j,int m ,int n,vector<vector<int>> &dp){
    if(i==m-1&&j==n-1)return 1;
    if(i>m-1 ||j>n-1)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    return gridUniquepath(i+1,  j,  m, n, dp)+gridUniquepath(i,  j+1,  m, n, dp);
    
    
}



//combination


int gridUniquepathcomb(int m,int n){
    int ans=1;
    for(int i=0;i<n-1;i++){
        ans*=(m+n-2-i);
        ans/=(i+1);
    }
    return ans;
    
}

int main(){
    int m=3;
    int n=2;
    cout<<griduniquepath(0, 0, 3, 2)<<endl;
    vector<vector<int>>  dp(m,vector<int>(n,-1));
    cout<<gridUniquepath(0,  0,  m,  n, dp)<<endl;
    cout<<gridUniquepathcomb(m, n);
    
    
}