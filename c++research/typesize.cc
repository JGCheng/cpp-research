#include <iostream>
using namespace std;

int main()
{
    cout <<"sizeof(char/(signed char))=" << sizeof(char) << endl;
    cout <<"sizeof(unsigned char)=" << sizeof(unsigned char) << endl;
    cout <<"sizeof(bool)="<<sizeof(bool)<<endl;
    cout <<"sizeof(void*)="<<sizeof(void*)<<endl;
    cout <<"sizeof(short[int]/(signed short [int]))=" << sizeof(signed short int) << endl;
    cout <<"sizeof(unsigned short [int])=" << sizeof(unsigned short int) << endl;
    cout <<"sizeof(int/(signed [int]))=" << sizeof(int) << endl;
    cout <<"sizeof(unsigned [int])=" << sizeof(unsigned int) << endl;
    cout <<"sizeof(long [int]/(signed long [int]))=" << sizeof(long int) << endl;
    cout <<"sizeof(unsigned long [int])=" << sizeof(unsigned long int) << endl;
    cout <<"sizeof(long long)=" << sizeof(long long) << endl;
    cout <<"sizeof(wchar_t(unsigned short)=" << sizeof(wchar_t) << endl;
    cout <<"sizeof(float)=" << sizeof(float) << endl;
    cout <<"sizeof(double)=" << sizeof(double) << endl;
    cout <<"sizeof(long double)=" << sizeof(long double) << endl;
    return 0;
}
