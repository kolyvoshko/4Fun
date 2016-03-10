#ifndef FACTORYMETHOD
#define FACTORYMETHOD

#include <string>

class Object
{
public:
    virtual std::string get_type() = 0;
    virtual ~Object(){}
};

class Three : public Object
{
public:
    std::string get_type(){return "three"; }
};

class Grass : public Object
{
public:
    std::string get_type(){return "grass"; }
};

class Stone : public Object
{
public:
    std::string get_type(){return "stone"; }
};


class Creator{
    virtual Object* factory_method() = 0;
};

class CreateThree : public Creator
{
public:
    Object* factory_method(){return new Three();}
};

class CreateGrass : public Creator
{
public:
    Object* factory_method(){return new Grass();}
};

class CreateStone : public Creator
{
public:
    Object* factory_method(){return new Stone();}
};

void test()
{
    static const size_t count = 3;
    CreateThree creator_three;
    CreateStone creator_stone;
    CreateGrass creator_grass;

    Creator*creators[count] = {&creator_three, &creator_stone, &creator_grass};

    for(size_t i = 0; i<count; i++){
        Object* object=creators[i]->factory_method();
        std::cout << object->get_type() << std::endl;
        delete object;
}

#endif // FACTORYMETHOD

