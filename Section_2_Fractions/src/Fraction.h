#pragma once
#include <string>

class Fraction {
public:
    Fraction(int numerator, int denominator);

    ~Fraction();

    Fraction reciprocal() const;

    Fraction multiply(int a) const;

    double toDouble() const;

    std::string toString() const;

    
    private:
    void convertToSimplestForm();

    int numerator;
    int denominator;
};
