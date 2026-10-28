#pragma once
#include <functional>
using namespace std;

class Click {
private:
    function<void()> func;
    bool hasfunc;

public:
    Click(): func(nullptr), hasfunc(false) {}
    void setClickCommand(std::function<void()> f)
    {
        hasfunc = true;
        func = f;
    }
    virtual void click()
    {
        if(hasfunc){
            func();
        }
    }
};

class DoubleClick {
private:
    function<void()> func;
    bool hasfunc;

public:
    DoubleClick(): func(nullptr), hasfunc(false) {}
    void setDoubleClickCommand(std::function<void()> f)
    {
        hasfunc = true;
        func = f;
    }
    virtual void doubleClick()
    {
        if(hasfunc){
            func();
        }
    }
};