#pragma once
#include <memory>
#include <list>
#include "event.h"
#include <vector>

using namespace std;

int ttime = 0;

class Window;

class Widget {
    string _name;
    Window* _parent;
    public:
    Widget(string name) :_name(name), _parent(nullptr) {}
    string getName() const { return _name; }
    Window* getParent() const { return _parent; }
    void setParent(Window * parent) {_parent = parent;}
    virtual bool get_back() {return false;}
    virtual ~Widget() {}
};

class Button :public Widget, public Click, public DoubleClick {
    public:
    Button(string name) :Widget(name) {}
};

class Checkbox :public Widget, public Click {
public:
    bool isget;
    vector<bool> history;
    vector<int> timetable;
    Checkbox(string name): Widget(name), Click(), isget(false) {}
    void click() override
    {
        history.push_back(isget);
        timetable.push_back(ttime);
        ttime ++;
        
        if(isget){
            isget = false;
        }else{
            isget = true;
        }
    }
    
    bool get_back() override
    {
        if(timetable.empty()){
            return false;
        }
        
        if(timetable.back() == ttime){
            timetable.pop_back();
            isget = history.back();
            history.pop_back();
            return true;
        }

        return false;
    }
};

class Window {
    
private:
    list<shared_ptr<Widget>> Widgets;

public:
    shared_ptr<Widget> getPointerByName(string name)
    {
        for(auto widget : Widgets){
            if(widget->getName() == name){
                return widget;
            }
        }

        return nullptr;
    }
    Widget& getElementByName(string name)
    {
        for(auto widget : Widgets){
            if(widget->getName() == name){
                return *widget;
            }
        }
    }

    bool addElement(shared_ptr<Widget> w)
    {
        for(auto widget : Widgets){
            if(widget->getName() == w->getName()){
                return false;
            }
        }

        Widgets.push_back(w);

        return true;
    }

    bool undo()
    {
        bool ret = false;
        ttime --;
        for(auto wid : Widgets){
            if(wid->get_back()){
                ret = true;
            }
        }
        if(!ret){
            ttime ++;
        }


        return ret;
    }
};
