#pragma once

#include <string>
using namespace std;

class Lamp {
public:
    virtual void up(int d) = 0;
    virtual int power() const = 0;
    virtual std::string report() const = 0;
    virtual Lamp* clone() const = 0;
    virtual ~Lamp() {}
};

class SteadyLamp: public Lamp
{
    string color;
    int level;
public:
    SteadyLamp(string c, int l): color(c), level(l) {}
    void up(int d) override
    {
        level += d;
    }

    int power() const
    {
        return level;
    }

    string report() const
    {
        string ret = "S:" + color + ":" + to_string(level);

        return ret;
    }

    Lamp* clone() const
    {
        Lamp* ret = new SteadyLamp(color, level);
        return ret;
    }
};

class PulseLamp: public Lamp
{
    string color;
    int low;
    int high;
public:
    PulseLamp(string c, int l, int h): color(c), low(l), high(h) {}
    void up(int d) override
    {
        low += d;
        high += d;
    }

    int power() const
    {
        int ret = (low + high)/2;

        return ret;
    }

    string report() const
    {
        string ret = "P:" + color + ":" + to_string(low) + "-" + to_string(high);

        return ret;
    }

    Lamp* clone() const
    {
        Lamp* ret = new PulseLamp(color, low, high);
        return ret;
    }
};



class Inspection {
private:
    Lamp* owned;
    Lamp* observed;
    bool frozen;

    const Lamp* current() const {
        return frozen ? owned : observed;
    }

public:
    Inspection(Lamp* lamp, bool frozen): observed(lamp), frozen(frozen)
    {
        if(frozen){
            owned = observed->clone();
        }
    }

    Inspection(const Inspection& other): observed(other.observed), frozen(other.frozen)
    {
        if(other.frozen){
            owned = other.owned->clone();
        }
    }

    Inspection& operator=(const Inspection& other)
    {
        observed = other.observed;
        frozen = other.frozen;
        if(other.frozen){
            owned = other.owned->clone();
        }

        return *this;
    }

    ~Inspection()
    {
        if(frozen){
            delete owned;
        }
    }

    std::string report()
    {
        if(frozen){
            return owned->report();
        }else{
            return observed->report();
        }
    }

    int power()
    {
        if(frozen){
            return owned->power();
        }else{
            return observed->power();
        }
    }
};
