#include "rational.h"

#include "math.h"

using namespace std;

Rational::Rational(long numerator, long denominator){
    m_isNegative = (numerator < 0) != (denominator < 0);
    m_numerator = abs(numerator);
    m_denominator = abs(denominator);
    reduce();
}

void Rational::reduce(){
    int a, b, rem;
    if (m_numerator > m_denominator){
        a = m_numerator;
        b = m_denominator;
    }
    else{
        a = m_denominator;
        b = m_numerator;
    }
    while (b != 0){
        rem = a % b;
        a = b;
        b = rem;
    }
    m_numerator /= a;
    m_denominator /= a;
}

Rational Rational::operator *(const Rational &rn2) const
{
    long int n,d;
    n = m_numerator * rn2.m_numerator;
    d = m_denominator * rn2.m_denominator;
    if(m_isNegative != rn2.m_isNegative){
        n = -n;
    }
    return Rational(n,d);
}

Rational Rational::operator /(const Rational &rn2) const
{
    long int n,d;
    n = m_numerator * rn2.m_denominator;
    d = m_denominator * rn2.m_numerator;
    if(m_isNegative != rn2.m_isNegative){
        n = -n;
    }
    return Rational(n,d);
}

Rational Rational::operator +(const Rational &rn2) const
{
    long int n,n1,n2,d;
    n1 = m_numerator * rn2.m_denominator;
    n2 = m_denominator * rn2.m_numerator;
    if(m_isNegative){
        n1 = -n1;
    }
    if(rn2.m_isNegative){
        n2 = -n2;
    }
    n = n1 + n2;
    d = m_denominator * rn2.m_denominator;
    return Rational(n,d);
}

Rational Rational::operator -() const
{
    long int n = m_isNegative? m_numerator : -m_numerator;
    return Rational(n, m_denominator);
}

Rational Rational::operator -(const Rational &rn2) const
{
    return *this + (-rn2);
}

ostream &operator<<(ostream &os, const Rational &rn){
    long int i = 0, n = rn.m_numerator, d = rn.m_denominator;

    /// division by zero handling
    if(0 == d){
        return os << "inf";
    }
    /// zero handling
    if( 0 == n){
        return os << '0';
    }
    /// add opening paranthesis and sign if negative
    if(rn.isNegative()){
        os << "(-";
    }
    /// extract the integer part
    if(rn.m_numerator > rn.m_denominator){
        i = n / d;
        n = n % d;
        os << i;
    }
    /// put the denominator if it's not zero or no integer extracted
    if( 0 != n ){
        if(n != rn.m_numerator)
            os << ' '; /// add space between integer and numerator
        os << n;
    }
    /// put the numerator if it's not zero
    if (1 != d){
        os << '/' << d;
    }
    /// add closing paranthesis if negative
    if(rn.isNegative()){
        os << ')';
    }
    return os;
}
