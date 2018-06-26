#include <iostream>
#include <cmath>
#include <iomanip>

int inputDecimal();
int powerOf2(int input);
void numInBinary(int decimalNum);

int main() {
    
    int decimal = inputDecimal();
    powerOf2(decimal);
    numInBinary(decimal);

    return 0;
}

// Function used for a number input
int inputDecimal() {
    
    unsigned int positiveNum;
    std::cout << "Input a positive number: ";
    std::cin >> positiveNum;
    return positiveNum;
}

// Function used for finding the
// highest exponent of 2 based on input
int powerOf2(int input) {
    
    int exp = 1;
    int i = 0;

    while(exp < input) {
        
        i++;
        exp = pow(2, i);  
    
        if(exp > input) {
            
            exp = pow(2, i - 1);
            break;
        }
    }

    return exp;
}

// Function used for converting the input
// from decimal to binary
void numInBinary(int decimalNum) {
    
    double largestPower = powerOf2(decimalNum);
    std::setprecision(1);

    while(largestPower != 0.5) {
        
        if(decimalNum >= largestPower) {
            
            std::cout << "1 ";
            decimalNum -= largestPower;
        } else {
            
            std::cout << "0 ";
        }

        // looping through each exponent of base 2
        // e.g. 128 - 128/2 = 64
        largestPower -= (largestPower/2);
    }

    std::cout << "\n";
}


