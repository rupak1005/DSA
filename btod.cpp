#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int binaryToDecimal(string binary) {
    int decimal = 0;
    int length = binary.length();
    
    for (int i = 0; i < length; ++i) {
        if (binary[i] == '1') {
            decimal += pow(2, length - 1 - i);
        }
    }
    
    return decimal;
}

int main() {
    string binary="1100";
    
    
    
    int decimal = binaryToDecimal(binary);
    cout <<  decimal << endl;

    return 0;
}
