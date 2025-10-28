#  Software Engineering Experiment – Calculator Project

##  Overview
This repository contains all experiment files for the **Software Engineering Laboratory**.  
The project implements a **Calculator System in C++** and demonstrates **Software Quality Planning**, **COCOMO Model**, and **ISO 9001 Standards**, along with **White Box** and **Black Box Testing**.

---

## Repository Structure

| Folder | Description |
|--------|--------------|
| **calculator/** | Contains the main Calculator program written in C++. |
| **cocomo & iso/** | Includes code and documentation for the COCOMO model, ISO standards, and quality planning. |
| **testing/** | Contains white box and black box testing codes using Google Test (GTest). |

---

##  Technologies Used
- **Language:** C++  
- **Testing Framework:** Google Test (GTest)  
- **Tools:** Git, Google Colab, Visual Studio Code  
- **Models Used:** COCOMO Model, ISO 9001 Quality Planning  

---

##  Example Code Snippets

### Calculator Example
```cpp
int divide(int a, int b) {
    if (b == 0) throw runtime_error("Division by zero!");
    return a / b;
}
 Testing Example (Google Test)
cpp

TEST(CalculatorBlackBoxTest, AddPositiveNumbers) {
    Calculator calc;
    EXPECT_EQ(calc.add(5, 3), 8);
}
 Testing Details
 Black Box Testing
Tests external behavior of the calculator without checking internal logic.
Covers:

Addition

Subtraction

Multiplication

Division

Power

Square Root

 White Box Testing
Tests internal structure, conditions, and loops of the calculator.
Covers:

Factorial

Prime Number Check

Power Function Conditions

Loop Coverage

 Quality Planning & ISO Standards
This project follows the ISO 9001 Quality Management System ensuring:

Process-based approach

Continuous improvement

Quality assurance and verification steps

The COCOMO Model is used for cost and effort estimation of the software project.
Formula used:

Effort = a × (KLOC)^b
Development Time = c × (Effort)^d
How to Run
 Run Calculator Code
bash

g++ calculator.cpp -o calculator
./calculator
 Run Testing Code
bash

g++ test_calculator.cpp -lgtest -lpthread -o test_calculator
./test_calculator
 Author
Kavyanshi Agarwal
B.E. CSE (Hons.) – CSBS
Chandigarh University
Course: Software Engineering 
Experiment: Cocomo estimation, Quality Planning with ISO Standards & Software Testing

 Git Commands Used
bash
Copy code
git init
git add .
git commit -m "Initial commit for calculator and testing project"
git branch -M main
git remote add origin https://github.com/<your-username>/<your-repo>.git
git push -u origin main
