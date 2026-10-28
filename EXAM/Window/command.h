#pragma once
#include "window.h"
#include <iostream>
#include <memory>
#include <list>
using namespace std;

class ClearAll {
    list<shared_ptr<Checkbox>> checkbox;
public:
    ClearAll(list<shared_ptr<Checkbox>> checkbox): checkbox(checkbox) {}
    void operator()()
    {
        for(auto cb : checkbox)
        {
            cb->history.push_back(cb->isget);
            cb->timetable.push_back(ttime);
            cb->isget = false;
        }

        ttime ++;
    }
};

class SelectAll {
    list<shared_ptr<Checkbox>> checkbox;
public:
    SelectAll(list<shared_ptr<Checkbox>> checkbox): checkbox(checkbox) {}
    void operator()()
    {
        for(auto cb : checkbox){
            cb->history.push_back(cb->isget);
            cb->timetable.push_back(ttime);
            cb->isget = true;
        }

        ttime ++;
    }
};

class Submit {
    list<shared_ptr<Checkbox>> checkbox;
public:
    Submit(list<shared_ptr<Checkbox>> checkbox): checkbox(checkbox) {};
    void operator()()
    {
        for(auto cb : checkbox){
            cout << cb->getName() << " is ";

            if(!cb->isget){
                cout << "not ";
            }

            cout << "selected" << endl;
        }
    }
};