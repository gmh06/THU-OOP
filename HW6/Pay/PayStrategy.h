#pragma once
#include <string>

class PayStrategy {	
public:
	PayStrategy() {}						
	virtual double pay(std::string name, double money)=0;
};


class NormalStrategy : public PayStrategy {	
public:
	double pay(std::string name, double money) override
	{
		return money;
	}
};

class SwiftStrategy : public PayStrategy {	
public:
	double pay(std::string name, double money) override
	{
		if(money <= 10000){
			return std::max(money - 10, 0.0);
		}else{
			return std::max(money*0.999, money - 20);
		}
	}
};

class BitcoinStrategy : public PayStrategy {	
public:
	double pay(std::string name, double money) override
	{
		return money - (name.size() + 8) * 0.01;
	}
};
