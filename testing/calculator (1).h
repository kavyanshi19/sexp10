#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdexcept>
#include <cmath>

class Calculator{
public:
    int add(int a, int b);
    int subtract(int a, int b);
    int multiply(int a, int b);
    int divide(int a, int b);
    double power(double base, double exponent);
    double squareRoot(double number);
    int factorial(int n);
    bool isPrime(int n);
};

#endif
