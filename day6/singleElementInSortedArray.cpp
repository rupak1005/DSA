#include<iostream>
using namespace std;



int singleElement(int a[],int n){
    int start =0;   
    int end=n-1;
    if(n==1){
        return a[0];    
    }
    while(start<=end){
        int mid=start+(end-start)/2;
        
        
        if(mid==0 && a[0]!=a[1]){
            return a[0];
        }
        if(mid==n-1 && a[n-1]!=a[n-2]){
            return a[mid];
        }
       
        
        if(a[mid-1]!=a[mid] && a[mid]!=a[mid+1]){
            return a[mid];
        }
        if(mid%2==0){
            if(a[mid-1]==a[mid]){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        else{
            if(a[mid-1]==a[mid])
            {
                start=mid+1;
                
            }
            else{
                end=mid-1;
            }
        }
        
    }
    return -1;

}

int main(){
    int a[]={1,1,2,3,3,4,4,8,8};
    int b[]={3,3,7,7,10,11,11};
    int n=sizeof(a)/sizeof(a[0]);
    int n2=sizeof(b)/sizeof(b[0]);
    int ans=singleElement(a,n);
    int ans2=singleElement(b,n2);
    cout<<ans<<endl;
    cout<<ans2;
}