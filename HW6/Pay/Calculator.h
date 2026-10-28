#pragma once
#include <string>
#include "OccupationStrategy.h"
#include "PayStrategy.h"

class Calculator {		
    OccupationStrategy* occupationStrategy;		
    PayStrategy* payStrategy;				

public:
    Calculator(OccupationStrategy* m_occupationStrategy, PayStrategy* m_payStrategy): 
        occupationStrategy(m_occupationStrategy), payStrategy(m_payStrategy) {}

    ~Calculator() {}

    double getSalary(double base, double bonus, double level)
    {
        return occupationStrategy->getSalary(base, bonus, level);
    }

    double pay(std::string name, double salary)
    {
        return payStrategy->pay(name, salary);
    }

};
