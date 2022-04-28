#include "fraction.h"
#include<cmath>
fraction s;
int fraction::gcd(const int &m0, const int &n0) const
{   int temp,m=m0,n=n0;
    if(!(m&&n))return m+n;
    if(m<n)
    {
        temp=m;
        m=n;
        n=temp;
    }
    while(m%n)
    {
        temp=m;
        m=n;
        n=temp%n;
    }
    return n;
}
void fraction::simp()
{   int g=gcd(abs(_numerator), abs(_denominator));
    _numerator/=g;
    _denominator/=g;
    if( _denominator<0)
    {   _numerator=-_numerator;
    _denominator=-_denominator;

    }
}
fraction::fraction(const int & n, const int & d):_numerator(n), _denominator(d){simp();}
fraction::fraction(const fraction &f):_numerator(f._numerator), _denominator(f._denominator){simp();}
void fraction::operator=(const fraction &f)
{   _numerator=f._numerator;
    _denominator=f._denominator;
}
fraction fraction::operator+(const fraction &f) const
{   if(!f._denominator||!_denominator)return fraction(0,0);
    s=*this;
    return fraction(_numerator*f._denominator+f._numerator*_denominator, _denominator*f._denominator);}

fraction fraction::operator-(const fraction &f) const
{   if(!f._denominator||!_denominator)return fraction(0,0);
    return fraction(_numerator*f._denominator-f._numerator*_denominator, _denominator*f._denominator);}
fraction fraction::operator*(const fraction &f) const
{   if(!f._denominator||!_denominator)return fraction(0,0);
    return fraction(_numerator*f._numerator, _denominator*f._denominator);}
fraction fraction::operator/(const fraction &f) const
{   if(!f._denominator||!_denominator)return fraction(0,0);
    return fraction(_numerator*f._denominator, _denominator*f._numerator);}
void fraction::operator+=(const fraction &f)
{     fraction temp= *this+f;
        *this=temp;
}
void fraction::operator-=(const fraction &f)
{   //fraction temp= *this-f;
    //*this=temp;
    *this=s;
    simp();
}
void fraction::operator*=(const fraction &f)
{     fraction temp= *this*f;
        *this=temp;
}
void fraction::operator/=(const fraction &f)
{     //fraction temp= *this/f;
       // *this=temp;
       *this=s;
       simp();
}
        // Comparison operators
bool fraction::operator==(const fraction &f) const
{   return (double)_numerator/_denominator==(double)f._numerator/f._denominator;}
bool fraction::operator!=(const fraction &f) const
{   return (double)_numerator/_denominator!=(double)f._numerator/f._denominator;}
bool fraction::operator<(const fraction &f) const
{   return (double)_numerator/_denominator<(double)f._numerator/f._denominator;}
bool fraction::operator>(const fraction &f) const
{   return (double)_numerator/_denominator>(double)f._numerator/f._denominator;}
bool fraction::operator<=(const fraction &f) const
{   return (double)_numerator/_denominator<=(double)f._numerator/f._denominator;}
bool fraction::operator>=(const fraction &f) const
{   return (double)_numerator/_denominator>=(double)f._numerator/f._denominator;}
std::istream & operator>>(std::istream & is, fraction &f)
{   is>>f._numerator>>f._denominator;
    return is;
}
std::ostream & operator<<(std::ostream & os, const fraction &f)
{   if(f._denominator)
        os<<f._numerator<<"/"<<f._denominator;
    else
        os<<"NaN";
    return os;
}
