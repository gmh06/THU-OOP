#pragma once

#include <iostream>
#include <string>
#include <sstream>

class Computer
{
    std::string name = "";
    int num = 0;
    int price = 0;
public:
    friend std::istream& operator>>(std::istream& in, Computer& c);
    friend std::ostream& operator<<(std::ostream& out, const Computer& c);
    bool operator<(const Computer& c) const;
    Computer& operator++();
    Computer& operator--();

    void setPrice(int p);
    std::string getName() const { return name; }
    int getNum() const { return num; };
    int getPrice() const { return price; };
};