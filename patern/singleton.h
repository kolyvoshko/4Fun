#ifndef SINGLETON
#define SINGLETON

class Singleton
{
private:
    Singleton(){std::cout << "Singleton" << std::endl;}
    ~Singleton(){std::cout << "~Singleton" << std::endl;}

    Singleton(Singleton const&) = delete;
    Singleton& operator=(Singleton const&) = delete;

public:
    static Singleton& Instance()
    {
        static Singleton s;
        return s;
    }

    void f() {std::cout << "Singleton->f()" << std::endl;}
};

#endif // SINGLETON

