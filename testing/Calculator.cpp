#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

class Calculator {
public:
    int add(int a, int b) { return a + b; }
    int subtract(int a, int b) { return a - b; }
    int multiply(int a, int b) { return a * b; }
    int divide(int a, int b) {
        if (b == 0) throw runtime_error("Division by zero!");
        return a / b;
    }
    double power(double base, double exponent) {
        if (base == 0 && exponent < 0) throw runtime_error("0 to negative power undefined!");
        return pow(base, exponent);
    }
    double squareRoot(double number) {
        if (number < 0) throw runtime_error("Square root of negative number!");
        return sqrt(number);
    }
    int factorial(int n) {
        if (n < 0) throw runtime_error("Factorial of negative number not defined!");
        int result = 1;
        for (int i = 2; i <= n; i++) result *= i;
        return result;
    }
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;
        for (int i = 3; i * i <= n; i += 2)
            if (n % i == 0) return false;
        return true;
    }
};
