#include <stdexcept>
#include <numeric>

class Rational {
private:
    int num;
    int denom;
    void Reduction() {
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
public:
    Rational() : num(0), denom(1) {};
    Rational(int n, int d) : num(n), denom(d) {
        Reduction();
    };
    int Numerator() const {
        return num;
    }
    int Denominator() const {
        return denom;
    }
    Rational operator + () const {
        return {num, denom};
    }
    Rational operator - () const {
        return {-num, denom};
    }
    Rational operator + (const Rational& rhs) const {
        return {num * rhs.Denominator() + rhs.Numerator() * denom, denom * rhs.Denominator()};
    }
    Rational operator - (const Rational& rhs) const {
        return {num * rhs.Denominator() - rhs.Numerator() * denom, denom * rhs.Denominator()};
    }
    Rational operator * (const Rational& rhs) const {
        return {num * rhs.Numerator(), denom * rhs.Denominator()};
    }
    Rational operator / (const Rational& rhs) const {
        return {num * rhs.Denominator(), denom * rhs.Numerator()};
    }
    Rational& operator += (const Rational& rhs) {
        *this = *this + rhs;
        return *this;
    }
    Rational& operator -= (const Rational& rhs) {
        *this = *this - rhs;
        return *this;
    }
    Rational& operator *= (const Rational& rhs) {
        *this = *this * rhs;
        return *this;
    }
    Rational& operator /= (const Rational& rhs) {
        *this = *this / rhs;
        return *this;
    }
    Rational operator + (int rhs) const {
        return {num + rhs * denom, denom};
    }
    Rational operator - (int rhs) const {
        return {num - rhs * denom, denom};
    }
    Rational operator * (int rhs) const {
        return {num * rhs, denom};
    }
    Rational operator / (int rhs) const {
        return {num, denom * rhs};
    }
    //
    friend Rational operator + (int lhs, const Rational& rhs) {
        return {lhs * rhs.Denominator() + rhs.Numerator(), rhs.Denominator()};
    }
    friend Rational operator - (int lhs, const Rational& rhs) {
        return {lhs * rhs.Denominator() - rhs.Numerator(), rhs.Denominator()};
    }
    friend Rational operator * (int lhs, const Rational& rhs) {
        return {lhs * rhs.Numerator(), rhs.Denominator()};
    }
    friend Rational operator / (int lhs, const Rational& rhs) {
        return {lhs * rhs.Denominator(), rhs.Numerator()};
    }
    //
    Rational& operator += (int rhs) {
        *this = *this + rhs;
        return *this;
    }
    Rational& operator -= (int rhs) {
        *this = *this - rhs;
        return *this;
    }
    Rational& operator *= (int rhs) {
        *this = *this * rhs;
        return *this;
    }
    Rational& operator /= (int rhs) {
        *this = *this / rhs;
        return *this;
    }
    bool operator == (const Rational& rhs) const {
        if (num == rhs.Numerator() && denom == rhs.Denominator()) {
            return true;
        }
        return false;
    }
    bool operator != (const Rational& rhs) const {
        if (num != rhs.Numerator() || denom != rhs.Denominator()) {
            return true;
        }
        return false;
    }
};

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
