#ifndef VIRTUAL_INHERITANCE
#define VIRTUAL_INHERITANCE

class A {
public:
    virtual void f() = 0;
    virtual ~A(){std::cout << "~A" << std::endl;}
};

class B: virtual public A
{
public:
    void f() {std::cout << "B->f()" << std::endl;}
    ~B(){std::cout << "~B" << std::endl;}
};

class C: virtual public A
{
public:
    void f() {std::cout << "C->f()" << std::endl;}
    ~C(){std::cout << "~C" << std::endl;}
};

class D: public B, public C
{

public:
    void f() {std::cout << "D->f()" << std::endl;}
    ~D(){std::cout << "~D" << std::endl;}
};


#endif // VIRTUAL_INHERITANCE

