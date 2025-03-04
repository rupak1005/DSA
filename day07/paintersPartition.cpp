#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;



bool isPossible(vector<int> arr,int n,int m,int maxAllowedTime){//o(n)
    int painters=1,time=0;
    for(int i=0;i<n;i++){
        if(arr[i]>maxAllowedTime) return false;//edge case
        if(time+arr[i]<=maxAllowedTime){
            time+=arr[i];
        }
        else{
            painters++;
            time=arr[i];
        }
        
    }
    return painters<=m?true:false;
}

int paintersPartition(vector<int>& arr,int n,int m,int sum){//o(nlog(sum))
    int start=*max_element(arr.begin(),arr.end());
    int end=sum;
    int ans=-1;
    
    if(m>n){//edge case
        return -1;
    }
    while(start<end){//o(log(sum))
        int mid=start+(end-start)/2;
        if(isPossible(arr,n,m,mid)){//left
            end=mid-1;
            ans=mid;
            
        }
        else//right
        {
            start=mid+1;
            
        }
    }
    return ans;
}



int main(){
    vector<int> arr={40,30,10,20};
    int n=arr.size();
    int m=2;
    int sum=0;
    for(int i=0;i<n;i++){//o(n)
        sum+=arr[i];
    }
    
    int ans=paintersPartition(arr,n,m,sum);//o(nlog(sum))
    cout<<ans;
}
