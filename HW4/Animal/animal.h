#pragma once

#include <string>

class Animal
{
public:
    std::string name;
    Animal(std::string name): name(name) {}
    virtual ~Animal() {};
    void action(){
        speak();
        swim();
    }
    virtual void speak() = 0;
    virtual void swim() = 0;
};