#include <iostream>

using namespace std;


/*
��˷�ʽ����λ����ڵ͵�ַ��С�˷�ʽ����λ����ڵ͵�ַ��
�����һ��32λ������0x12345678��ŵ�һ�����ͱ�����int���У�������ͱ������ô�˻���С��ģʽ���ڴ��еĴ洢���±���ʾ��Ϊ�����������ʹ��OP0��ʾһ��32λ���ݵ�����ֽ�MSB��Most Significant Byte����ʹ��OP3��ʾһ��32λ��������ֽ�LSB��Least Significant Byte����

��ַƫ�� ���ģʽ С��ģʽ
0x00 12��OP0�� 78��OP3��
0x01 34��OP1�� 56��OP2��
0x02 56��OP2�� 34��OP1��
0x03 78��OP3�� 12��OP0�� 
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
