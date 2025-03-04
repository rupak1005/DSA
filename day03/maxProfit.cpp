#include<iostream>
using namespace std;




int maxProfit(int prices[],int n){

    int maxProfit=0;
    int bestBuy=prices[0];


    for(int i=1;i<n;i++){

        if(prices[i]>bestBuy){
            maxProfit=max(maxProfit,prices[i]-bestBuy);

        }
        bestBuy=min(bestBuy,prices[i]);

    }
    return maxProfit;

}
int main(){
    int prices[]={7,1,5,3,6,4};
    int n=sizeof(prices)/sizeof(int);

    int ans=maxProfit(prices,n);
    
    cout<<ans;



    
}