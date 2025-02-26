#include<iostream>
#include<vector>
using namespace std;



bool isValid(vector<int> arr,int n,int m,int maxAllowedpages){//o(n)
    int students=1,pages=0;
    for(int i=0;i<n;i++){
        if(arr[i]>maxAllowedpages) return false;//edge case
        if(pages+arr[i]<=maxAllowedpages){
            pages+=arr[i];
        }
        else{
            students++;
            pages=arr[i];
        }
        
    }
    return students<=m?true:false;
}

int bookAllocation(vector<int> arr,int n,int m,int sum){//o(nlog(sum))
    int start=0;
    int end=sum;
    int ans=-1;
    
    if(m>n){//edge case
        return -1;
    }
    while(start<end){//o(log(sum))
        int mid=start+(end-start)/2;
        if(isValid(arr,n,m,mid)){//left
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
    vector<int> arr={15,17,20};
    int n=arr.size();
    int m=2;
    int sum=0;
    for(int i=0;i<n;i++){//o(n)
        sum+=arr[i];
    }
    
    int ans=bookAllocation(arr,n,m,sum);//o(nlog(sum))
    cout<<ans;
}
