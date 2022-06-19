#ifndef FRACTION_H_INCLUDED
#define FRACTION_H_INCLUDED
#include<iostream>
using namespace std;

class Fraction
{
    protected:

        int num;
        int den;

    public:

        Fraction();
        Fraction(int n, int d);
        Fraction(const Fraction &obj);

        void reducing_fractions(int& n, int& d);

        friend istream& operator >>(istream& in, Fraction& obj);
        friend ostream& operator<< (ostream& out, Fraction& obj);

        Fraction operator+(Fraction obj);
        Fraction operator-(Fraction obj);
        Fraction operator*(Fraction obj);
        Fraction operator/(Fraction obj);

        bool operator> (const Fraction &right);
        bool operator>= (const Fraction &right);
        bool operator< (const Fraction &right);
        bool operator<= (const Fraction &right);
        bool operator== (const Fraction &right);
};


#endif // FRACTION_H_INCLUDED
