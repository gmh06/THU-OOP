#include "ComputerCollection.h"

std::istream& operator>>(std::istream& in, ComputerCollection& cc)
{
    Computer cpt;
    in >> cpt;
    cc.cc.push_back(cpt);

    return in;
}

std::ostream& operator<<(std::ostream& out, const ComputerCollection& cc)
{
    for(auto cpt : cc.cc){
        out << cpt << "\n";
    }

    return out;
}

Computer& ComputerCollection::operator[](const std::string i)
{
    for(auto& cpt : cc){
        if(cpt.getName() == i)
            return cpt;
    }

    return cc[0];
}

bool cmp(const Computer& a, const Computer& b)
{
    if(a.getNum() != b.getNum())
        return a.getNum() > b.getNum();
    else
        return a.getPrice() > b.getPrice();
}

void ComputerCollection::sortByScore()
{
    std::sort(cc.begin(), cc.end(), cmp);

    return;
}