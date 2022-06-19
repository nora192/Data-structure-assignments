#ifndef MATRIXCALCULATOR_H_INCLUDED
#define MATRIXCALCULATOR_H_INCLUDED
#include<iostream>
#include"Matrix.h"
using namespace std;
class  MatrixCalculator
{
private:
public:

    MatrixCalculator();
    void menue();
};


MatrixCalculator:: MatrixCalculator()
{}


void MatrixCalculator:: menue()
{
    int c;

    while(true)
    {
        cout << "Enter number of operation you want from the following operations" << endl;
        cout << "(1) addition" << endl;
        cout << "(2) subtraction" << endl;
        cout << "(3) multiplication" << endl;
        cout << "(4) Transpose" << endl;
        cout << "(5) Exit" << endl;

        cin >> c;
        if(c == 1)
        {
            Matrix<int> m1;
            Matrix<int> m2;

            cout << "First matrix" << endl;
            cin >> m1;
            cout << endl << "Second matrix" << endl;
            cin >> m2;
            if(m1.getcol()==m2.getcol() && m1.getrow()==m2.getrow())
            {
                Matrix<int> m3 = m1 + m2;
                cout << endl << "matrix 1 + matrix 2 = " << endl << m3 << endl;
                continue;
            }
            else
                cout << "The two matrices should have the same dimensions ." << endl;
        }
        if(c == 2)
        {
            Matrix<int> m1;
            Matrix<int> m2;
            cout << "First matrix" << endl;
            cin >> m1;
            cout << endl << "Second matrix" << endl;
            cin >> m2;
            if(m1.getcol()==m2.getcol() && m1.getrow()==m2.getrow())
            {
                Matrix<int> m3 = m1 - m2;
                cout << endl << "matrix 1 - matrix 2 = " << endl << m3 << endl;
                continue;
            }
            else
                cout << "The two matrices should have the same dimensions ." << endl;
        }

        if(c == 3)
        {
            Matrix<int> m1;
            Matrix<int> m2;

            cout << "First matrix" << endl;
            cin >> m1;
            cout << endl << "Second matrix" << endl;
            cin >> m2;
            if(m1.getcol() == m2.getrow())
            {
                Matrix<int> m3 = m1 * m2;
                cout << endl << "matrix 1 * matrix 2 = " << endl << m3 << endl;
                continue;
            }
            else
                cout << "The number of columns of the first matrix" << endl
                << "and number of rows of the second matrix must be the same " << endl;
        }

        if(c == 4)
        {
            Matrix<int>m1;
            cin >> m1;
            Matrix<int> t = m1.transpose();
            cout << endl << "transposed matrix:" << endl << t << endl;
            continue;
        }
        if(c == 5)
            break;
        else{
            cout << "Invalid input." << endl;
            break;
        }
    }
}

#endif // MATRIXCALCULATOR_H_INCLUDED
