//#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "Fraction.h"
using namespace std;

Fraction::Fraction()
{}

Fraction::Fraction(int n, int d)
{
    num = n;
    den = d;
}

Fraction:: Fraction(const Fraction &obj)
{
    num = obj.num;
    den = obj.den;
}

void Fraction:: reducing_fractions(int& n, int& d)
{
    if(n != 0){
        if(d % n == 0){
            d = d / n;
            n /= n;
            if(d < 0)
            {
                d *= -1;
                n *= -1;
            }
        }
        if(d % n != 0){
            int x = n;
        if(n < 0)
            {
                x = n*-1;
            }
            for(int i=x; i>1; i--){
                if(x%i == 0 && d%i == 0){
                    n /= i;
                    d /= i;
                    break;
                }
            }
        }
        else{
            n = n;
            d = d;
        }
    }
}

istream& operator >>(istream& in, Fraction& obj)
{
    cout << "enter numerator: ";
    in >> obj.num;
    cout << endl;
    cout << "enter denominator: ";
    in >> obj.den;
    if(obj.den == 0)
    {
        cout << "you can not divide by 0." << endl;
        exit(EXIT_FAILURE);
    }
    return in;
}

ostream& operator<< (ostream& out, Fraction& obj)
{
    if( (obj.den<0 && obj.num>0) || (obj.den<0 && obj.num<0) ){
        obj.den *= -1;
        obj.num *= -1;
    }
    obj.reducing_fractions(obj.num, obj.den);
    if(obj.num == 0)
        out << 0 ;
    else if(obj.den == 0)
    {   out << "you can not divide by 0 " << endl;
        exit(EXIT_FAILURE);
    }
    else if(obj.num == obj.den)
        out << 1;
    else if(obj.den == 1)
        out << obj.num ;
    else
        out << obj.num << "/" << obj.den ;
    return out;
}


Fraction Fraction:: operator+(Fraction obj)
{
    Fraction temp;
    temp.num = (num * obj.den) + (den * obj.num);
    temp.den = den * obj.den;
    reducing_fractions(temp.num,temp.den);
    return temp;
}

Fraction Fraction:: operator-(Fraction obj)
{
    Fraction temp;
    temp.num = (num * obj.den) - (den * obj.num);
    temp.den = den * obj.den;
    temp.reducing_fractions(temp.num,temp.den);
    return temp;
}

Fraction Fraction:: operator*(Fraction obj)
{
    Fraction temp;
    temp.num = num * obj.num;
    temp.den = den * obj.den;
    reducing_fractions(temp.num,temp.den);
    return temp;
}

Fraction Fraction:: operator/(Fraction obj)
{
    Fraction temp;
    temp.num = num * obj.den;
    temp.den = den * obj.num;
    reducing_fractions(temp.num, temp.den);
    return temp;
}

bool Fraction:: operator> (const Fraction &right)
{
    bool status;
    float f1 = num / den;
    float f2 = right.num / right.den;
    if(f1 > f2)
    {
        status = true;
    }
    else
    {
        status = false;
    }
    return status;
}

bool Fraction:: operator>= (const Fraction &right)
{
    bool status;
    float f1 = num / den;
    float f2 = right.num / right.den;

    if(f1 >= f2)
    {
        status = true;
    }
    else
    {
        status = false;
    }

    return status;
}

bool Fraction:: operator< (const Fraction &right)
{
    bool status;
    float f1 = num / den;
    float f2 = right.num / right.den;

    if(f1 < f2)
    {
        status = true;
    }
    else
    {
        status = false;
    }

    return status;
}

bool Fraction:: operator<= (const Fraction &right)
{
    bool status;
    float f1 = num / den;
    float f2 = right.num / right.den;

    if(f1 <= f2)
    {
        status = true;
    }
    else
    {
        status = false;
    }

    return status;

}

bool Fraction:: operator== (const Fraction &right)
{
    bool status;
    float f1 = num / den;
    float f2 = right.num / right.den;

    if(f1 == f2)
    {
        status = true;
    }
    else
    {
        status = false;
    }

    return status;

}
