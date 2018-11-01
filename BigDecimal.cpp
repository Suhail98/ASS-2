#include "BigDecimal.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;
BigDecimal::BigDecimal(std::string num)
{
    this -> num = num;

     if(num[0] == '-')
        Sign = num[0] , isNegative = true, this-> num =num.substr(1,this -> num.length()-1);
    else if(num[0] == '+')
        Sign = num[0] ,isNegative = false,this-> num = num.substr(1,this->num.length()-1);
    else
        isNegative = false;
}

BigDecimal::BigDecimal(int num)
{
    stringstream ss;
    ss << num;
    this -> num =  ss.str();;
}

BigDecimal BigDecimal:: operator+(BigDecimal others)
{
    string num3;
    std::cout << this-> isNegative << " " << others.isNegative << endl;
    if(this -> isNegative == others.isNegative)
    {
        bool carry = 0;
            //cout << "hi " << endl;

        while(this -> num.size() < others.num.size())
            this -> num = "0" + this -> num;

        while(others.num.size() < this -> num.size())
            others.num = "0" + others.num;

        for(int i = this-> num.length()-1; i >=0 ; i--)
        {
            int x =  this -> num[i] + others.num[i] - 96 + carry;
            if(x >= 10)
                x -= 10, carry = true;
            else
                carry = false;
            num3 = char(x + '0') + num3;

        }

        if(carry)
            num3 = "1" + num3;
        std::cout << endl << num3 << endl;
        char sign = '+';
        if(this -> isNegative)
            sign = '-';


        BigDecimal b(sign+num3);
        return b;



    }
    else
    {
        if(this -> isNegative)
        {BigDecimal b = *(this);
        b.isNegative = false;
        return others - b;
        }
        else
        {
        BigDecimal b = others;
        b.isNegative = false;
        return *(this) - b;
        }
    }

}



 BigDecimal BigDecimal::operator- (BigDecimal others)
{

    if ( this -> isNegative == others.isNegative && ! this -> isNegative)
    {
        cout << "hi " << endl;
        string max1 = others.num,  min1 = others.num ;char sign = '+';

        if(this -> num.size() > others.num.size())
        {
            max1 = this -> num, min1 = others.num;
              if(min1 == this -> num && max1 == others.num)
                    sign = '-';
            while(min1.size() < max1.size())
                min1 = '0' + min1;
        }
        else if( others.num.size() > this -> num.size())
        {
            max1 = others.num, min1 = this -> num;
              if(min1 == this -> num && max1 == others.num)
                    sign = '-';
            while(min1.size() < max1.size())
                min1 = '0' + min1;

        }
        else
        {
            for(int i = 0; i < others.num.size(); i++)
                if(this -> num[i] > others.num[i])
                    {max1 = this -> num, min1 = others.num ;
                          if(min1 == this -> num && max1 == others.num)
                            sign = '-';
                    }
                else if(this -> num[i] < others.num[i])
                    {max1 = others.num, min1 = this -> num;
                       if(min1 == this -> num && max1 == others.num)
                            sign = '-';
                    }


                    }

        string num3;
        for(int i = min1.length()-1; i >= 0; i--)
        {
            num3 =  char( '9' - min1[i] + '0') + num3;

        }

        bool carry = false;
        string num4;
        for(int i = num3.length()-1; i >=0 ; i--)
        {
            int x = max1[i] + num3[i] - 96 + carry;
            if(x >= 10)
                x -= 10, carry = true;
            else
                carry = false;
            num4 = char(x + '0') + num4;

        }

        if(carry)
            for(int i = num3.length()-1; i >=0 ; i--)
            {
                int x =  num4[i] - 48 + carry;
                if(x >= 10)
                    x -= 10, carry = true;
                else
                    carry = false;
                num4[i] = char(x+'0');

            }


        cout << sign << num4 << endl;
        BigDecimal b(sign+num4);
        return b;

    }
    else if( this-> isNegative && others.isNegative)
    {
        BigDecimal b = others;
        b.isNegative = false;
        BigDecimal c = *(this) + b;
        c.isNegative = true;
        return c;
    }
    else if(this -> isNegative)
    {
        others.isNegative = true;
        return *(this) + others;
    }


}

BigDecimal  BigDecimal:: operator=(int x)
{
    stringstream ss;
    ss << x;
    this -> num =  ss.str();
    return *(this);
}

BigDecimal  BigDecimal :: operator=(string x)
{
    this -> num = x;
    return *(this);
}

 string BigDecimal :: getString()
{
    return this-> num;
}
istream& operator>>(istream& in , BigDecimal& num)
{
    string s; in >> s;
    num = s;
    return in;
}
ostream& operator<<(ostream& out , BigDecimal num)
{

    out << num.getString();

    return out;
}



