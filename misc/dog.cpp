#include "dog.h"

Dog::~Dog()
{}

Dog::Dog()
{}

Dog::Dog(std::string _breed, int _age, std::string _name, std::string _sex)
{
    breed = _breed;
    age = _age;
    name = _name;
    sex = _sex;
}

void Dog::print()
{
    std::cout << breed << ", " << age << ", " << name << ", " << sex << std::endl;
}

