#include <iostream>
using namespace std;

class Base
{
public:
    Base(){cout << "Base() called" << endl;}
    virtual ~Base(){cout << "~Base() called" << endl;}
};

class Derived: public Base
{
public:
    Derived(){cout << "Derived() called" << endl;}
    virtual ~Derived(){cout << "~Derived() called" << endl;}
};

int main()
{
    Base *obj = new Derived();
    delete obj;    
    return 0;
}

