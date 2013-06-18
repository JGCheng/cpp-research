#include <iostream>

using namespace std;


/*
大端方式将高位存放在低地址，小端方式将低位存放在低地址。
如果将一个32位的整数0x12345678存放到一个整型变量（int）中，这个整型变量采用大端或者小端模式在内存中的存储由下表所示。为简单起见，这里使用OP0表示一个32位数据的最高字节MSB（Most Significant Byte），使用OP3表示一个32位数据最低字节LSB（Least Significant Byte）。

地址偏移 大端模式 小端模式
0x00 12（OP0） 78（OP3）
0x01 34（OP1） 56（OP2）
0x02 56（OP2） 34（OP1）
0x03 78（OP3） 12（OP0） 
*/

// If the CPU is little-endian, return 1, otherwise, it is big-endian, return 0.
int checkEndian()
{
    union v{
        int a;
        char b;
    };

    v c;
    c.a = 1;
    return (c.b == 1);
}

int main()
{
    if ( checkEndian() )
        cout <<" System is LITTLE endian." << endl;
    else
        cout <<" System is BIG endian." << endl;

    return 0;
}
