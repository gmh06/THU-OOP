#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include "Computer.h"

class ComputerCollection
{
    std::vector<Computer> cc;

public:
    friend std::istream& operator>>(std::istream& in, ComputerCollection& cc);
    friend std::ostream& operator<<(std::ostream& out, const ComputerCollection& cc);
    Computer& operator[](const std::string i);
    void sortByScore();
};