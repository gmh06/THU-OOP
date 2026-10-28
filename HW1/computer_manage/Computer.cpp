#include "Computer.h"

std::istream& operator>>(std::istream& in, Computer& c)
{
    std::string s;
    in >> s;
    for(auto& ch : s){
        if(ch == '-')
            ch = ' ';
    }
    std::istringstream ss(s);
    ss >> c.name >> c.num >> c.price;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Computer& c)
{
    out << c.name << "-num-" << c.num << "-price-" << c.price;
    return out;
}

bool Computer::operator<(const Computer& c) const
{
    if(num < c.num)
        return true;
    else if(num == c.num)
        if(price < c.price)
            return true;

    return false;
}

Computer& Computer::operator++()
{
    ++num;
    return *this;
}

Computer& Computer::operator--()
{
    if(num > 0)
        --num;
    return *this;
}

void Computer::setPrice(int p)
{
    price = p;
    return;
}