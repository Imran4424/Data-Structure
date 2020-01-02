// palindrome checking

#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    int number;
    cin >> number;
    
    int normal = 0, reverse = 0, powerCount = 1;
    
    while(0 != number) {
        
        int digit = number % 10;
        
        reverse = reverse * 10 + digit;
        
        normal = digit * powerCount + normal;
        
        powerCount = powerCount * 10;
        
        number = number /10;
    }
    
    cout << normal << " " << reverse << endl;
    
    if(normal == reverse) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not Palindrome" << endl;
    }
}
