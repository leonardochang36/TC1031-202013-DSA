#ifndef _DOG_H
#define _DOG_H

#include <string>
#include <iostream>

class Dog
{
private:
    std::string breed;
    int age;
    std::string name;
    std::string sex;

public:
    ~Dog();
    Dog();
    Dog(std::string _breed, int _age, std::string _name, std::string _sex);

   int get_age() {return age;};
    /* 
    implement here get and set methods    
    */
   void print();

   static bool compare_age(Dog &a, Dog &b)
    {
        return a.get_age() < b.get_age();
    };

};

#endif