#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string decimalToBinary(int n) {
   
    if (n == 0) return "0";

    string binary = "";

   
    while (n > 0) {
        binary += to_string(n % 2);
        n = n / 2; 
    }

   
    reverse(binary.begin(), binary.end());
    
    return binary;
}

int main() {
    int num=12;
   

    string binary = decimalToBinary(num);
    cout << binary << endl;

    return 0;
}
