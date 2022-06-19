#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#include<iostream>
using namespace std;
template <class T>
class Matrix
{
    protected:
    int row,column;
    T ** mat;

    public:
    Matrix();
    Matrix(int r, int c);
    Matrix(const Matrix<T>& obj);

    Matrix operator+ (const Matrix<T>& right);
    Matrix operator- (const Matrix<T>& right);
    Matrix operator* (const Matrix<T>& right);

    int getrow();
    int getcol();

    Matrix<T> transpose();

    template<class T2>
    friend ostream& operator<< (ostream& out, Matrix<T2>& obj);

    template <class T2>
    friend istream& operator>> (istream& in, Matrix<T2>& obj);

    ~Matrix();
};

template <class T>
Matrix<T> :: Matrix(){}

template <class T>
Matrix<T> :: Matrix(int r, int c)
{
    this->row = r;
    this->column = c;
    this->mat = new T*[row];
    for(int i=0; i<row; i++)
    {
        this->mat[i] = new T[column];
    }
}

template <class T>
Matrix<T>:: Matrix(const Matrix<T>& obj)
{
    this->row = obj.row;
    this->column = obj.column;
    this->mat = new T*[row];
    for(int i=0; i<row; i++)
    {
        this->mat[i] = new T[column];
    }

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
            this->mat[i][j] = obj.mat[i][j];
    }

}

template <class T2>
ostream& operator<< (ostream& out, Matrix<T2>& obj)
{
    for(int i=0; i<obj.row; i++)
    {
        for(int j=0; j<obj.column; j++)
        {
            out << obj.mat[i][j] << " ";
        }
        out << endl;
    }
    return out;
}

template <class T2>
istream& operator>> (istream& in, Matrix<T2>& obj)
{
    cout << "Enter number of rows: ";
    in >> obj.row;
    cout << endl << "Enter number of columns: ";
    cin >> obj.column;
    obj.mat = new T2* [obj.row];
    for(int i=0; i<obj.row; i++)
    {
        obj.mat[i] = new T2 [obj.column];
    }
    cout << endl << "enter elements:" << endl;
    for(int i=0; i<obj.row; i++)
    {
        for (int j=0; j<obj.column; j++)
        {
            in >> obj.mat[i][j];
        }
    }
    return in;
}

template<class T>
int Matrix<T>:: getrow(){
    return row;}

template<class T>
int Matrix<T>:: getcol(){
    return column;}

template<class T>
Matrix<T> Matrix<T>:: transpose()
{
    Matrix<T> temp(column,row);
    for(int i=0; i<temp.row; i++)
    {
        for(int j=0; j<temp.column; j++)
        {
            temp.mat[i][j] = 0;
        }
    }

    for(int i=0; i<temp.row; i++)
    {
        for(int j=0; j<temp.column; j++)
        {
            temp.mat[i][j] = mat[j][i];
        }
    }
    return temp;
}

template <class T>
Matrix<T> Matrix<T> ::operator+ (const Matrix<T>& right)
{
    Matrix<T> temp(row, column);
    for(int i=0; i<temp.row; i++)
    {
        for(int j=0; j<temp.column; j++)
        {
            temp.mat[i][j] = mat[i][j] + right.mat[i][j];
        }
    }
    return temp;

}

template <class T>
Matrix<T> Matrix<T> ::operator- (const Matrix<T>& right)
{
    Matrix<T> temp(row, column);
    for(int i=0; i<temp.row; i++)
    {
        for(int j=0; j<temp.column; j++)
        {
            temp.mat[i][j] = mat[i][j] - right.mat[i][j];
        }
    }
    return temp;

}

template <class T>
Matrix<T> Matrix<T> ::operator* (const Matrix<T>& right)
{
    Matrix<T> temp(row, right.column);
    for(int i=0; i<temp.row; i++)
    {
        for(int j=0; j<temp.column; j++)
        {
            temp.mat[i][j] = 0;
        }
    }

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<temp.column; j++)
        {
            for(int k=0; k<column; k++)
            {
                temp.mat[i][j] += mat[i][k] * right.mat[k][j];
            }

        }
    }

    return temp;
}
template<class T>
Matrix<T>:: ~Matrix()
{
    for(int i=0; i<row; i++)
    {
        delete[] mat[i];
    }
}

#endif // MATRIX_H_INCLUDED
