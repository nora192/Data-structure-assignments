#include <iostream>
#include<string>
#include<stdlib.h>
using namespace std;

int nSign = 0 ;
class BigInt
{
private:
    string strNum;
    int sum;
    int carry = 0;
    int sub;
public:
    BigInt(){}
    BigInt(int decInt)
    {
        strNum = to_string(decInt);
    }
    BigInt(string decStr)
    {
        for(int i=1; i<decStr.length(); i++)
        {
            if(decStr[0] == '-')
            {
                if((decStr[i] > '9' || decStr[i] < '0'))
                {
                    exit(EXIT_FAILURE);
                    break;
                }
                else
                    continue;
            }
            else if(decStr[0] <= '9' && decStr[0] >= '0')
            {
                if((decStr[i] > '9' || decStr[i] < '0'))
                {
                    exit(EXIT_FAILURE);
                    break;
                }
                else
                {
                    continue;
                }
            }
            else{
                exit(EXIT_FAILURE);
                break;
            }
            }

        strNum = decStr;
        remove_left_zaros(strNum);
    }


    friend ostream& operator << (ostream& out, BigInt b)
    {
        out << b.strNum << endl;
        return out;
    }
    void operator = (const BigInt&obj)
    {
        strNum = obj.strNum;
        sum = obj.sum;
        carry = obj.carry;
        sub = obj.sub;
    }
/*******************************************************/

    bool operator==(const BigInt& right)
    {
        bool status;
        if(strNum == right.strNum)
            status = true;
        else
            status = false;
        return status;
    }


    int checksign(string n1,string n2)
    {
        if (n1[0] == '-' && n2[0] != '-')
        {
            return 1;
        }
        else if(n1[0] == '-' && n2[0] == '-')
        {
            return 1;
        }
        else if(n1[0] != '-' && n2[0] != '-')
        {
            return 1;
        }
        else if(n1[0] != '-' && n2[0] == '-')
        {
            return 1;
        }

        else
        {
            return 0;
        }
    }
/*****************************************************/

    BigInt operator+ (BigInt anotherDec)
    {
        string str1;
        if(strNum[0] != '-' && anotherDec.strNum[0] != '-')
        {
            if ( strNum.length() < anotherDec.strNum.length() )
            {
                return anotherDec + *this;
            }
            
            if (strNum.length() >= anotherDec.strNum.length())
            {
                int j=anotherDec.strNum.length() - 1;
                for (int i=strNum.length() - 1;  i>=0; i--,j--)
                {
                    if(j < 0)
                    {
                        sum = strNum[i] - '0' + carry;
                    }
                    else if(j >= 0)
                    {
                        sum = (strNum[i] - '0') + (anotherDec.strNum[j] - '0');
                        sum += carry;
                    }
                    if(sum > 9 && i != 0)
                    {
                        sum -= 10;
                        carry = 1;
                        str1.insert(0,to_string(sum));
                    }
                    else if(sum > 9 && i == 0)
                    {
                        carry = 0;
                        str1.insert(0,to_string(sum));
                    }
                    else if(sum <= 9)
                    {
                        carry = 0;
                        str1.insert(0,to_string(sum));
                    }
                }
            }
/************************************/
        if (nSign == 1)
        {
            string temp = "-";
            for(int i=0; i<str1.length(); i++)
            {
                temp += str1[i];
            }
            str1 = temp;
            nSign = 0;
        }
        
        remove_left_zaros(str1);
        return str1;
        }
/************************************************************************/

        else if(strNum[0] == '-' && anotherDec.strNum[0] != '-')
        {
            BigInt a = *this;
            removasign(a.strNum);
            bool check = checkbigger(a.strNum, anotherDec.strNum);
            if (check == true)
            {
                nSign = checksign(strNum, anotherDec.strNum);
                return a - anotherDec;
            }
            else if(check == false)
            {
                return anotherDec - a;
            }
        }
/*************************************************************************/

        else if(strNum[0] != '-' && anotherDec.strNum[0] == '-')
        {

            BigInt a = anotherDec;
            removasign(a.strNum);
            bool check = checkbigger(strNum, a.strNum);
            if(check == false)
            {
                nSign = checksign(strNum,anotherDec.strNum);
                return a - *this;
            }
            else if(check == true)
            {
                return *this - a;
            }
        }
/*********************************************************************/

        else if(strNum[0] == '-' && anotherDec.strNum[0] == '-')
        {
            BigInt a = anotherDec;
            removasign(a.strNum);
            return *this - a;
        }
    }

/*****************************************************************/
    bool checkbigger(string num1, string num2)
    {
        if (num1.length() == num2.length())
        {
            for(int i=0; i<num1.length(); i++)
            {
                if(num1[i] >= num2[i])
                {
                    return true;
                }
                else if(num1[i] < num2[i])
                {
                    return false;
                }
            }
        }
        else if(num1.length() < num2.length())
            return false;
        else if (num1.length() > num2.length())
            return true;
    }
/***********************************************************/

    string removasign(string &sNum)
    {
        string temp;
        for(int i=1; i<sNum.length(); i++)
        {
            temp += sNum[i];
        }
        sNum = temp;
        return sNum;
    }
/**************************************************/

    void remove_left_zaros(string &num)
    {
        if (num[0]=='0')
        {
            int i=0;
            while (num[i]=='0')
                i++;

            if (i==(num.length()))
                num.erase(0,i-1);
            else
                num.erase(0,i);
        }
        else if (num[0]=='-' && num[1]=='0')
        {
            int i=0;
            while (num[i+1]=='0')
                i++;
            if (i==num.length() - 1){
                num = '0';
            }
            else{
                num.erase(1,i);
            }
        }
    }
/*******************************************************************/
    BigInt operator - ( BigInt anotherDec)
    {
        string str2;
        if(strNum[0] != '-' && anotherDec.strNum[0] != '-')
        {
            bool ret = checkbigger(strNum, anotherDec.strNum);
            if ( ret == false )
            {
                nSign = checksign(strNum, anotherDec.strNum);
                return anotherDec - *this;
            }

            if(ret == true)
            {
                BigInt a = *this;
                int j = anotherDec.strNum.length() - 1;
                for(int i=a.strNum.length()-1; i>=0; i--,j--)
                {
                    if (j < 0)
                    {
                        sub = a.strNum[i] - '0';
                    }
                    else if(j >= 0)
                    {
                        if ((a.strNum[i] - '0') >= (anotherDec.strNum[j] - '0'))
                        {
                            sub = (a.strNum[i] - '0') - (anotherDec.strNum[j] - '0');
                        }

                        else if((a.strNum[i] - '0') < (anotherDec.strNum[j] - '0'))
                        {
                            int current = a.strNum[i] - '0';
                            if (current == 0)
                            {
                                current += 10;
                                int c = i-1;
                                current = a.strNum[c] - '0';
                                while(current == 0 && c>=0)
                                {
                                   a.strNum[c] = '9';
                                   c--;
                                   current = a.strNum[c] - '0';
                                }
                                current = current - 1;
                                string val = to_string(current);
                                a.strNum.replace(c,1,val);
                                sub = 10 - (anotherDec.strNum[j] - '0');

                            }
                            else if(current != 0 && current < (anotherDec.strNum[j] - '0') )
                            {
                               current += 10;
                               int c1 = i-1;
                               while(a.strNum[c1] == '0' && c1 >= 0)
                               {
                                    a.strNum[c1] = '9';
                                    c1--;
                               }

                               int pre = (a.strNum[c1] - '0') -1;
                               string prev = to_string(pre);
                               a.strNum.replace((c1),1,prev);
                               sub = current - (anotherDec.strNum[j] - '0');

                            }
                        }
                }
                 str2.insert(0,to_string(sub));
            }
        }
/*******************************************************/
        if (nSign == 1)
        {
            string temp = "-";
            for(int i=0; i<str2.length(); i++)
            {
                temp += str2[i];
            }
            str2 = temp;
            nSign = 0;
        }
            remove_left_zaros(str2);
            return str2 ;
        }

/*******************************************************************/

        else if (strNum[0] == '-' && anotherDec.strNum[0] != '-')
            {
                nSign = checksign(strNum, anotherDec.strNum);
                BigInt a = *this;
                removasign(a.strNum);
                return a + anotherDec ;
            }

/**************************************************************************/
        else if (anotherDec.strNum[0] == '-' && strNum[0] != '-')
            {
                removasign(anotherDec.strNum);
                return anotherDec + *this;
            }
/**************************************************************************/
        else if(strNum[0] == '-' && anotherDec.strNum[0] == '-')
        {
            BigInt a = *this;
            BigInt b = anotherDec;
            removasign(a.strNum);
            removasign(b.strNum);
            bool check = false;
            check = checkbigger(a.strNum, b.strNum);
            if (check == true)
            {
                nSign = checksign(strNum, anotherDec.strNum);
                return a - b;
            }
            else if ( check == false)
            {
                return b - a  ;
            }
        }
    }
/*******************************************************************************/

    int Size()
    {
        return strNum.length();
    }

};
/*********************************************************/

void testCase_1()
{
    BigInt num1("12345678");
    BigInt num2("987456321");
    BigInt num3 = num1 + num2;
    BigInt num4 = num1 - num2;
    BigInt expectedVal_1("999801999");
    BigInt expectedVal_2("-975110643");
    if(num3 == expectedVal_1 && num4 == expectedVal_2)
        cout << "test passed" << endl;
    else
        cout << "test failed" << endl;
}
/***********************************************/

void testCase_2()
{
    BigInt num1("-987456321");
    BigInt num2("-789654123");
    BigInt num3 = num1 + num2;
    BigInt num4 = num1 - num2;
    BigInt expectedVal_1("-1777110444");
    BigInt expectedVal_2("-197802198");
    if(num3 == expectedVal_1 && num4 == expectedVal_2)
        cout << "test passed" << endl;
    else
        cout << "test failed" << endl;
}
/**********************************************/

void testCase_3()
{
    BigInt num1("-789654123");
    BigInt num2("123654789");
    BigInt num3 = num1 + num2;
    BigInt num4 = num1 - num2;
    BigInt expectedVal_1("-665999334");
    BigInt expectedVal_2("-913308912");
    if(num3 == expectedVal_1 && num4 == expectedVal_2)
        cout << "test passed" << endl;
    else
        cout << "test failed" << endl;
}
/*************************************************/
void testCase_4()
{
    BigInt num1("0123654789");
    BigInt num2("-789654123");
    BigInt num3 = num1 + num2;
    BigInt num4 = num1 - num2;
    BigInt expectedVal_1("-665999334");
    BigInt expectedVal_2("913308912");
    if(num3 == expectedVal_1 && num4 == expectedVal_2)
        cout << "test passed" << endl;
    else
        cout << "test failed" << endl;
}
/*************************************************/
void testCase1_5()
{
    BigInt num1("000123654789");
    BigInt num2("9875200");
    BigInt num3 = num1 + num2;
    BigInt num4 = num1 - num2;
    BigInt expectedVal_1("133529989");
    BigInt expectedVal_2("113779589");
    if(num3 == expectedVal_1 && num4 == expectedVal_2)
        cout << "test passed" << endl;
    else
        cout << "test failed" << endl;
}


int main()
{
    testCase_1();
    testCase_2();
    testCase_3();
    testCase_4();
    testCase1_5();
}