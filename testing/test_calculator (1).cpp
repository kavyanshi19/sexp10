#include <gtest/gtest.h>
#include "Calculator.cpp"   // include your Calculator class

// ---------- WHITE BOX TESTS ----------

TEST(CalculatorWhiteBoxTest, Addition) {
    Calculator calc;
    EXPECT_EQ(calc.add(5, 3), 8);
    EXPECT_EQ(calc.add(-5, 5), 0);
}

TEST(CalculatorWhiteBoxTest, DivisionByZero) {
    Calculator calc;
    EXPECT_THROW(calc.divide(10, 0), std::runtime_error);
}

TEST(CalculatorWhiteBoxTest, Factorial) {
    Calculator calc;
    EXPECT_EQ(calc.factorial(5), 120);
    EXPECT_EQ(calc.factorial(0), 1);
    EXPECT_THROW(calc.factorial(-3), std::runtime_error);
}

TEST(CalculatorWhiteBoxTest, SquareRoot) {
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.squareRoot(25), 5);
    EXPECT_THROW(calc.squareRoot(-9), std::runtime_error);
}

TEST(CalculatorWhiteBoxTest, IsPrime) {
    Calculator calc;
    EXPECT_TRUE(calc.isPrime(7));
    EXPECT_FALSE(calc.isPrime(9));
    EXPECT_FALSE(calc.isPrime(1));
}

// ---------- BLACK BOX TESTS ----------

TEST(CalculatorBlackBoxTest, BasicOperations) {
    Calculator calc;
    EXPECT_EQ(calc.add(10, 5), 15);
    EXPECT_EQ(calc.subtract(10, 5), 5);
    EXPECT_EQ(calc.multiply(10, 5), 50);
    EXPECT_EQ(calc.divide(10, 2), 5);
}

TEST(CalculatorBlackBoxTest, PowerFunction) {
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.power(2, 3), 8);
    EXPECT_THROW(calc.power(0, -2), std::runtime_error);
}

// Main for GTest
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


