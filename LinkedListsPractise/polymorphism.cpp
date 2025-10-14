#include<iostream>
using namespace std;

class Base {
public:
    void msg() { cout << "In Base\n"; }
};

class Derived: public Base {
public:
    virtual void msg() { cout << "In Derived\n"; }
};

int main() {
    Base* b;
    Derived d; Base BB;
    b = &d;
    b->msg();  
    b= &BB;
    b->msg();
    d.msg();

}
