#ifndef __V_TABLE_H
#define _V_TABLE_H

typedef void (* Fun)(void);

class Parent {
    public:
    virtual void f() { cout << "    Base::f()" << endl; }
    virtual void g() { cout << "    Base::g()" << endl; }
    virtual void h() { cout << "    Base::h()" << endl; }

};

class Child1:public Parent {
    public:
    virtual void f1() { cout << "   Child::f1()" << endl;}
    virtual void g1() { cout << "   Child::g1()" << endl;}
    virtual void h1() { cout << "   Child::h1()" << endl; cout << "This pointer:"<< (int*)this<<endl;}
};

#endif
