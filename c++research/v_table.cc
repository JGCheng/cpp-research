#include <iostream>
#include <stdlib.h>

using namespace std;

#include "v_table.h"


// the Base without child class has virtual class.
void print_virtual_table_address(Parent *p)
{
    
    Fun pFun = NULL;
    long * pvtbl = (long*)*(long*)p;

    cout << "   The object address::"<< (long*)p<<endl;
    cout << "   The virtual table address::"<< pvtbl <<endl;
    while (pvtbl != 0 && *pvtbl != 0) // This algorithm is effective for the class without children class.
    {
        cout << "   The function address in virtual table:" << pvtbl << endl;
        pFun = (Fun)*(pvtbl + 0); // f()
        cout << "   Execute the function: " << endl;
        pFun();

        pvtbl ++;

    }

   
}

int main()
{

    cout << "Class has virutual function but without child class:" << endl;
    Parent parent;
    print_virtual_table_address(&parent);

    cout << endl << "Child :" << endl;
    Child1 child1;
    print_virtual_table_address(&child1);

    return 0;
}

