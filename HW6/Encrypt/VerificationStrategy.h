#pragma once
# include <string>

class VerificationStrategy{
public:
	virtual std::string verify(std::string mes) = 0;
};

class PrefixStrategy: public VerificationStrategy
{
public:
	std::string verify(std::string mes) override
	{
		return mes.substr(0, 3);
	}
};

class IntervalStrategy: public VerificationStrategy
{
public:
	std::string verify(std::string mes) override
	{
		std::string veri;
		for(int i = 0; 2*i < mes.size(); i ++){
			veri.push_back(mes[2*i]);
		}

		return veri;
	}
};
