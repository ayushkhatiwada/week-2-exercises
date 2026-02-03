#include "Fraction.h"
#include <string>
#include <numeric> // You may use std::gcd to calculate a greatest common divisor.

Fraction::Fraction(int numerator, int denominator)
    : numerator(numerator),
    denominator(denominator) {
        convertToSimplestForm();
    }

Fraction::~Fraction() = default;

Fraction Fraction::reciprocal() const {
    return Fraction(denominator, numerator);
}

Fraction Fraction::multiply(int a) const {
    return Fraction(a * numerator, denominator);
}

double Fraction::toDouble() const {
    return static_cast<double>(numerator) / static_cast<double>(denominator);
}

std::string Fraction::toString() const {
    if (numerator == 0) return std::string("0");
    return std::to_string(numerator) + "/" + std::to_string(denominator);
}

void Fraction::convertToSimplestForm() {
    int gcd = std::gcd(numerator, denominator);
    numerator = numerator / gcd;
    denominator = denominator / gcd;
}
