#include "FractionCalculator.h"
#include "Fraction.h"
#include<vector>
#include <iostream>
using namespace std;


FractionCalculator:: FractionCalculator()
{}

void FractionCalculator:: calculator()
{
    vector<Fraction>v;
    int choice;
    while(true)
    {
        cout << endl << "Which of the following operation you want:" << endl;
        cout << "(1) add" << endl;
        cout << "(2) subtract" << endl;
        cout << "(3) multiply" << endl;
        cout << "(4) divide" << endl;
        cout << "(5) reduce " << endl;
        cout << "(6) get previous results" << endl;
        cout << "(7) Exit" << endl;
        cout << endl << "Enter number: ";
        cin >> choice;

        if (choice == 1)
        {
            Fraction f1, f2;
            cout << "First Fraction " << endl ;
            cin >> f1;
            cout << endl;
            cout << "Second Fraction " << endl;
            cin >> f2;
            Fraction result;
            result = f1 + f2;
            v.push_back(result);
            cout << "f1 + f2 = "<< result << endl;
        }
        if(choice == 2)
        {
            Fraction f1, f2;
            cout << "First Fraction " << endl ;
            cin >> f1;
            cout << endl;
            cout << "Second Fraction " << endl;
            cin >> f2;
            Fraction result = f1 - f2;
            v.push_back(result);
            cout <<"f1 - f2 = "<< result << endl;
        }
        if(choice == 3)
        {
            Fraction f1, f2;
            cout << "First Fraction " << endl ;
            cin >> f1;
            cout << endl;
            cout << "Second Fraction " << endl;
            cin >> f2;
            Fraction result = f1 * f2;
            v.push_back(result);
            cout << " f1 * f2 = " << result << endl;
        }
        if(choice == 4)
        {
            Fraction f1, f2;
            cout << "First Fraction " << endl ;
            cin >> f1;
            cout << endl;
            cout << "Second Fraction " << endl;
            cin >> f2;
            Fraction result = f1 / f2;
            v.push_back(result);
            cout << "f1 / f2 = " << result << endl;
        }

        if(choice == 5)
        {
            Fraction f1;
            cin >> f1;
            v.push_back(f1);
            cout << endl;
            cout << "first fraction= " << f1 <<  endl;
        }

        if(choice == 6)
        {
            if(v.size() == 0)
                cout << "There is no element yet." << endl;
            else
            {
                cout << "The previous results: " ;
                for(int i=0; i<v.size(); i++)
                {
                    cout << v[i] << "  ";
                }
                cout << endl;
            }

        }

        if(choice == 7)
        {
            cout << "Thank you" << endl;
            break;
        }
    }
}

