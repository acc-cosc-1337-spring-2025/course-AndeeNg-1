//add include statements
#include "repetition.h"
#include <string>
#include <iostream>
using std::cout, std::cin;

//add function(s) code here

    int factorial(int num) {
        int result = 1;
        for (int i = 2; i <= num; i++) {
            result *= i;
        }
        return result;
    }
    
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }