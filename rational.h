#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational
{
public:
    Rational(long int numerator, long int denominator);

    void reduce();
    long int numerator() const{return m_numerator;}
    long int denominator() const{return m_denominator;}
    bool isNegative() const{return m_isNegative;}

    Rational operator *(const Rational& rn2) const;
    Rational operator /(const Rational& rn2) const;
    Rational operator +(const Rational& rn2) const;
    Rational operator -() const ;
    Rational operator -(const Rational &rn2) const;


private:
    long int m_numerator;
    long int m_denominator;
    bool m_isNegative;

    friend std::ostream& operator<<(std::ostream& os, const Rational& rn);
};
#endif // RATIONAL_H
