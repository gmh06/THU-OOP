#pragma once

class OccupationStrategy {
public:								
	OccupationStrategy() {}
	virtual double getSalary(double base, double bonus, double level)=0;
};

class SalesmanStrategy : public OccupationStrategy {
public:
	double getSalary(double base, double bonus, double level) override
	{
		if(level < 60){
			return base;
		}else if(level < 70){
			return base + 0.6 * bonus;
		}else if(level < 80){
			return base + 0.7 * bonus;
		}else{
			return base + bonus;
		}
	}
};

class DeveloperStrategy : public OccupationStrategy {	
public:
	double getSalary(double base, double bonus, double level) override
	{
		return base + bonus * level/100;
	}
};