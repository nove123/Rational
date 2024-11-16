#pragma once

class Rational {
private:
    int num;
    int denom;
    void Reduction();
public:
    Rational();
    Rational(int n, int d);
    int Numerator() const;
    int Denominator() const;
    Rational operator + () const;
    Rational operator - () const;
    Rational operator + (const Rational& rhs) const;
    Rational operator - (const Rational& rhs) const;
    Rational operator * (const Rational& rhs) const;
    Rational operator / (const Rational& rhs) const;
    Rational& operator += (const Rational& rhs);
    Rational& operator -= (const Rational& rhs);
    Rational& operator *= (const Rational& rhs);
    Rational& operator /= (const Rational& rhs);
    Rational operator + (int rhs) const;
    Rational operator - (int rhs) const;
    Rational operator * (int rhs) const;
    Rational operator / (int rhs) const;
    friend Rational operator + (int lhs, const Rational& rhs);
    friend Rational operator - (int lhs, const Rational& rhs);
    friend Rational operator * (int lhs, const Rational& rhs);
    friend Rational operator / (int lhs, const Rational& rhs);
    Rational& operator += (int rhs);
    Rational& operator -= (int rhs);
    Rational& operator *= (int rhs);
    Rational& operator /= (int rhs);
    bool operator == (const Rational& rhs) const;
    bool operator != (const Rational& rhs) const;
};

bool operator < (const Rational& lhs, const Rational& rhs);
bool operator > (const Rational& lhs, const Rational& rhs);
bool operator <= (const Rational& lhs, const Rational& rhs);
bool operator >= (const Rational& lhs, const Rational& rhs);
