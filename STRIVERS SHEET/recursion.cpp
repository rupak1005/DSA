include<iostream>

#include<algorithm>
using namespace std;

void Print1toN(int i,int n){
    if(i>n)return;
    cout<<i<<" ";
    Print1toN(i+1,n);
    
    
}

//backtracking 
void print1toNB(int i,int n){
    if(i<1)return ;
    print1toNB(i-1,n);
    cout<<i<<" ";
}



//Print N to 1 using recursion


void printNto1(int n){
    if(n<1)return;
    cout<<n<<" ";
    printNto1(n-1);
    
}

//Sum of first N Natural Numbers

int sumtoN(int n){
    
    if(n<1)return 0;
    
    return  n+sumtoN(n-1);
}

//using a loop

int sumtoNloop(int n){
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=i;
    }
    return sum;
}
//factorial of a number using recursion
int fact(int n){
    if(n==0)return 1;
    return n*fact(n-1);
}

//factorial using loop

int factloop(int n){
    int fact=1;
    for(int i=1;i<=n;i++){
        fact*=i;
    }
    return fact;
}



//reverse an array
void printarray(int array[],int n){
    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
}

//using another array
void reversarray(int arr[],int n){
    int array[n];
    for(int i=0;i<n;i++){
        array[i]=arr[n-i-1];
    }
    printarray(array, n);
    
}

// reverse using swap
// 
void reverseswap(int arr[],int n){
    int a=0;
    int b=n-1;
    while(a<b){
        swap(arr[a],arr[b]);
        a++;
        b--;
    }
    printarray(arr,  n);
}


// reverse array using recusrion
// 
void reverseRecursion(int arr[],int start,int end){
    
    while(start<end){
        // swap the elements at start and end indices
        swap(arr[start],arr[end]);
        // move the start index forward and the end index backward
        return reverseRecursion(arr,start+1,end-1);
    }
    printarray(arr,5);
}


//using library


void reversealgo(int arr[],int n){
    
    reverse(arr,arr+n);
    
    printarray(arr, n);
}


// chack palindrome 
// 
bool ispalindrome(string str){
    int left=0;
    int right=str.length()-1;
    while(left<right){
        // check if the left and right characters are not alphanumeric
        if(!isalnum(str[left])){
            
            left++;
        }  
        // check if the left and right characters are not alphanumeric
        else
        if(!isalnum(str[right])){
            
            right--;
        }
        // check if the left and right characters are not equal
        else if(tolower(str[left])!=tolower(str[right])){
            return false;
        
        }
        // if the left and right characters are equal, move to the next characters
        else{
            left++;
            right--;
        }
    }
    return true;
}


// check palindorme recursion?


bool ispalinrecur(int i,string str){
    // / Base Condition
        // If i exceeds half of the string means all the elements 
        // are compared, we return true.
    if(i>=str.length())return true;
    // If the character at i and n-i-1 are not same, we return false.
    if(str[i]!=str[str.length()-i-1])return false;
    // If the character at i and n-i-1 are same, we call the function
    return ispalinrecur(i+1,str);
    
}
//rpint fibonacci series

void printfib(int n){
    cout<<0<<" ";
    
    int slast=0;
    int last=1;
    cout<<slast+last<<" ";
    int curr;
    for(int i=2;i<n;i++){
        curr=last+slast;
        slast=last;
        last=curr;
        cout<<curr<<" ";
    }
    
}
// fibonacci recursion

int fib(int n){
    if(n==0)return 0;
    if(n==1)return 1;
    int last=fib(n-1);
    int slast=fib(n-2);
    return last+slast;
}
int main(){
    // Print1toN(1,100);
    // print1toNB(100, 100);
    // printNto1(100);
    // cout<<sumtoN(10);
    // cout<<endl;
    // cout<<sumtoNloop(10);
    // cout<<fact(5);
    // cout<<factloop(5);
    // int array[5]={1,2,3,4,5};
    // printarray(array,5);
    // reversarray(array, 5);
    // reverseswap(array,5);
    // reverseRecursion(array, 0,5-1);
    // reversealgo(array, 5);
    // string str = "ABCDCBA";
    //  bool ans = ispalinrecur(0,str);
   
    //  if (ans == true) {
    //    cout << "Palindrome";
    //  } else {
    //    cout << "Not Palindrome";
    //  }
    // 
    // cout<<fib(4);
    // printfib(10);
    
}


