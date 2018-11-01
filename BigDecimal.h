#ifndef BIGDECIMAL_H
#define BIGDECIMAL_H
#include <iostream>

using namespace std;
class BigDecimal
{
    public:

        BigDecimal(std::string num);
        BigDecimal(int num);
        BigDecimal operator+(BigDecimal others);
        BigDecimal operator-(BigDecimal others);
        friend ostream& operator<<(ostream& out , BigDecimal num);
        friend istream& operator>>(istream& in , BigDecimal& num);
        BigDecimal  operator=(int x);
        BigDecimal  operator=(string x);
        string getString();


    protected:

    private:
        char Sign;
        string num;
        bool isNegative;

};

#endif // BIGDECIMAL_H
