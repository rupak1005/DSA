#include <iostream>
using namespace std;

int main() {
    char ch = 'Z'; 
    
    
    for (int i = 0; i < 5; i++) {
        cout << ch-- << " ";
    }
    cout << endl;

    
    for (int i = 0; i < 1; i++) cout << " "; 
    ch = 'U'; 
    for (int i = 0; i < 4; i++) {
        cout << ch-- << " ";
    }
    cout << endl;

  
    for (int i = 0; i < 2; i++) cout << " "; 
    ch = 'Q'; 
    for (int i = 0; i < 3; i++) {
        cout << ch-- << " ";
    }
    cout << endl;

   
    for (int i = 0; i < 3; i++) cout << " "; 
    ch = 'N';
    for (int i = 0; i < 2; i++) {
        cout << ch-- << " ";
    }
    cout << endl;

    
    for (int i = 0; i < 4; i++) cout << " "; 
    cout << "L"; 
    cout << endl;

    return 0;
}
