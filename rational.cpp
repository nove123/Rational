#include "rational.h"
#include <stdexcept>
#include <numeric>

void Rational::Reduction() {
    if (denom == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    if (denom < 0) {
        num *= -1;
        denom *= -1;
    }
    int g = std::gcd(num, denom);
    num /= g;
    denom /= g;
}
Rational::Rational() : num(0), denom(1) {};
Rational::Rational(int n, int d) : num(n), denom(d) {
    Reduction();
};
int Rational::Numerator() const {
    return num;
}
int Rational::Denominator() const {
    return denom;
}
Rational Rational::operator + () const {
    return {num, denom};
}
Rational Rational::operator - () const {
    return {-num, denom};
}
Rational Rational::operator + (const Rational& rhs) const {
    return {num * rhs.Denominator() + rhs.Numerator() * denom, denom * rhs.Denominator()};
}
Rational Rational::operator - (const Rational& rhs) const {
    return {num * rhs.Denominator() - rhs.Numerator() * denom, denom * rhs.Denominator()};
}
Rational Rational::operator * (const Rational& rhs) const {
    return {num * rhs.Numerator(), denom * rhs.Denominator()};
}
Rational Rational::operator / (const Rational& rhs) const {
    return {num * rhs.Denominator(), denom * rhs.Numerator()};
}
Rational& Rational::operator += (const Rational& rhs) {
    *this = *this + rhs;
    return *this;
}
Rational& Rational::operator -= (const Rational& rhs) {
    *this = *this - rhs;
    return *this;
}
Rational& Rational::operator *= (const Rational& rhs) {
    *this = *this * rhs;
    return *this;
}
Rational& Rational::operator /= (const Rational& rhs) {
    *this = *this / rhs;
    return *this;
}
Rational Rational::operator + (int rhs) const {
    return {num + rhs * denom, denom};
}
Rational Rational::operator - (int rhs) const {
    return {num - rhs * denom, denom};
}
Rational Rational::operator * (int rhs) const {
    return {num * rhs, denom};
}
Rational Rational::operator / (int rhs) const {
    return {num, denom * rhs};
}
//friend
Rational operator + (int lhs, const Rational& rhs) {
    return {lhs * rhs.Denominator() + rhs.Numerator(), rhs.Denominator()};
}
Rational operator - (int lhs, const Rational& rhs) {
    return {lhs * rhs.Denominator() - rhs.Numerator(), rhs.Denominator()};
}
Rational operator * (int lhs, const Rational& rhs) {
    return {lhs * rhs.Numerator(), rhs.Denominator()};
}
Rational operator / (int lhs, const Rational& rhs) {
    return {lhs * rhs.Denominator(), rhs.Numerator()};
}
//
Rational& Rational::operator += (int rhs) {
    *this = *this + rhs;
    return *this;
}
Rational& Rational::operator -= (int rhs) {
    *this = *this - rhs;
    return *this;
}
Rational& Rational::operator *= (int rhs) {
    *this = *this * rhs;
    return *this;
}
Rational& Rational::operator /= (int rhs) {
    *this = *this / rhs;
    return *this;
}
bool Rational::operator == (const Rational& rhs) const {
    if (num == rhs.Numerator() && denom == rhs.Denominator()) {
        return true;
    }
    return false;
}
bool Rational::operator != (const Rational& rhs) const {
    if (num != rhs.Numerator() || denom != rhs.Denominator()) {
        return true;
    }
    return false;
}

bool operator < (const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() * rhs.Denominator() < rhs.Numerator() * lhs.Denominator();
}
bool operator > (const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() * rhs.Denominator() > rhs.Numerator() * lhs.Denominator();
}
bool operator <= (const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() * rhs.Denominator() <= rhs.Numerator() * lhs.Denominator();
}
bool operator >= (const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() * rhs.Denominator() >= rhs.Numerator() * lhs.Denominator();
}
