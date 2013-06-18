#include <cstdio>
#include <iostream>
#include <typeinfo>

using namespace std;

class Point
{
    public:
        Point()
        {
            cout<<"Point constructor"<<endl;
        }

        virtual void func_hs()
        {
            cout<<"Point::func_hs"<<endl;
            printf("the address of this --func_hs:%p\n",&Point::func_hs);
        }
        virtual void  func_zzy()
        {
            cout<<"Point::func_zzy"<<endl;
            printf("the address of this --func_zzy:%p\n",&Point::func_zzy);
        }

        static void print()
        {
            //相对地址,在虚表指针之后.0x4 0x8 0xc --------->point to member
            printf("&Point::x=%p\n&Point::y=%p\n&Point::z=%p\n",
                    &Point::x,&Point::y,&Point::z);
        }

        void printThis()
        {
            //float *
            printf("&this->x=%p\n&this->y=%p\n&this->z=%p\n",
                    &this->x,&this->y,&this->z);
        }

        void printVt()
        {
            printf("the address of object,this:%p\nthe address of vt:%p\n",
                    this,(void*)*(int*)this);
        }
        void callVtFuncs(int num=2)
        {
            cout<<endl<<endl;

            typedef void (*Funp)(void);


            for(int i=0;i<num;i++)
            {
                Funp funp=(Funp)*((int*)*(int*)this+i);
                printf("%p\n",((int*)*(int*)this+i));
                printf("Point::callVtFuncs=>address of this fun:%p\n",funp);
                if(i==2||i==3)
                {
                    continue;
                }
                funp();
            }
        }

        void printVirtualFunAddress()
        {
            cout<<endl<<endl;
            printf("func_hs:%p\nfunc_zzy:%p\nfunc_zzzy:%p\n",
                    &Point::func_hs,&Point::func_zzy,
                    &Point::func_zzzy);
            printf("%p\n",&Point::func_zzzy);

        }
        virtual ~Point()
        {
            // printf("%p\n",&Point::~Point);
            cout<<"Point destructor"<<endl;
        }
        virtual void  func_zzzy()
        {
            cout<<"Point::func_zzzy"<<endl;
            printf("the address of this --func_zzzy:%p\n",&Point::func_zzzy);
        }

    protected:
        float x,y,z;
};


int main(int argc, char *argv[])
{
    Point point;
    Point::print();
    point.printThis();
    point.printVt();
    point.callVtFuncs(5);
    point.printVirtualFunAddress();
    printf("sizeof func:%u\n",sizeof(&main));
    printf("%p\n",&main);

    printf("sizeof memfunc:%u\n",sizeof(&Point::printVirtualFunAddress));
    printf("%p\n",&Point::printVirtualFunAddress);

    printf("%p\n",&Point::func_zzzy);

    printf("sizeof virtmemfunc:%u\n",sizeof(&Point::func_zzzy));
    cout<<typeid(point).name()<<endl;

    return 0;
}
