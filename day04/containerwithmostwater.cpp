#include<iostream>
using namespace std;


int maxWater(int height[],int n){
    int maxwater=0;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int w=j-i;
            int h=min(height[i],height[j]);
            int area=h*w;

            maxwater=max(maxwater,area);
        }
    }
    return maxwater;


}



int maxWaterOP(int height[],int n){


    int i=0,j=n-1,maxwater=0;



    while(i<j){
        int w=j-i;
        int h=min(height[i],height[j]);
        int area=h*w;
        maxwater=max(maxwater,area);

        height[i]<height[j]?i++:j--;
    }
    return maxwater;
}

int main(){
    int height[]={1,8,6,2,5,4,8,3,7};
    int n=sizeof(height)/sizeof(int);
    int ans=maxWater(height,n);
    int ans1=maxWaterOP(height,n);
    cout<<ans<<" "<<endl;
    cout<<ans1<<endl;
}