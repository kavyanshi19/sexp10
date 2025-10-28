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
        return a / b;}
    double power(double base, double exponent) {
        if (base == 0 && exponent < 0) throw runtime_error("0 to negative power undefined!");
        return pow(base, exponent);}
    double squareRoot(double number) {
        if (number < 0) throw runtime_error("Square root of negative number!");
        return sqrt(number);}
    int factorial(int n) {
        if (n < 0) throw runtime_error("Factorial of negative number not defined!");
        int result = 1;
        for (int i = 2; i <= n; i++) result *= i;
        return result;}
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) return false;}
        return true; }
};
int main() {
    Calculator calc;
    int choice;
    do {
        cout << "\nCalculator Menu\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Power\n";
        cout << "6. Square Root\n";
        cout << "7. Factorial\n";
        cout << "8. Check Prime\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        try {
            if (choice == 1) {
                int a, b;
                cout << "Enter two numbers: ";
                cin >> a >> b;
                cout << "Result = " << calc.add(a, b) << endl;}
            else if (choice == 2) {
                int a, b;
                cout << "Enter two numbers: ";
                cin >> a >> b;
                cout << "Result = " << calc.subtract(a, b) << endl;}
            else if (choice == 3) {
                int a, b;
                cout << "Enter two numbers: ";
                cin >> a >> b;
                cout << "Result = " << calc.multiply(a, b) << endl;}
            else if (choice == 4) {
                int a, b;
                cout << "Enter two numbers: ";
                cin >> a >> b;
                cout << "Result = " << calc.divide(a, b) << endl;}
            else if (choice == 5) {
                double a, b;
                cout << "Enter base and exponent: ";
                cin >> a >> b;
                cout << "Result = " << calc.power(a, b) << endl;}
            else if (choice == 6) {
                double n;
                cout << "Enter number: ";
                cin >> n;
                cout << "Result = " << calc.squareRoot(n) << endl; }
            else if (choice == 7) {
                int n;
                cout << "Enter number: ";
                cin >> n;
                cout << "Result = " << calc.factorial(n) << endl;}
            else if (choice == 8) {
                int n;
                cout << "Enter number: ";
                cin >> n;
                if (calc.isPrime(n))
                    cout << n << " is Prime" << endl;
                else
                    cout << n << " is Not Prime" << endl;}
            else if (choice == 0) {
                cout << "Exiting... Goodbye!\n";}
            else {
                cout << "Invalid choice!\n";}}
        catch (exception &e) {
            cout << "Error: " << e.what() << endl;
        }} 
		while (choice != 0);
    return 0;
	}

