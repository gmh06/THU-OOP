#pragma once
#include "event.h"
#include <vector>
using namespace std;

class Chocolate: public EventInterface
{
    EventInterface* gp = nullptr;

    public:

    void add_mate(EventInterface* mate)
    {
        gp = mate;
    }

    void zoo(EventInterface* mate) override
    {
        increase_mood(5);
        add_mate(mate);
    }

    void shop(EventInterface* mate) override
    {
        increase_mood(1);
    }

    void birthday() override
    {
        increase_mood(1);
        if(gp){
            increase_mood(5);

            gp->increase_mood(1);
        }
    }
};

class Strawberry: public EventInterface
{
    vector<EventInterface*> gp;

    public:

    void add_mate(EventInterface* mate)
    {
        for(auto i : gp){
            if(i == mate){
                return;
            }
        }

        gp.push_back(mate);
    }

    void zoo(EventInterface* mate) override
    {
        increase_mood(1);
        Chocolate* choc = dynamic_cast<Chocolate*>(mate);
        if(choc){
            increase_mood(5);
        }
    }

    void shop(EventInterface* mate) override
    {
        increase_mood(5);
        Chocolate* choc = dynamic_cast<Chocolate*>(mate);
        if(choc){
            increase_mood(5);
        }

        add_mate(mate);
    }

    void birthday() override
    {
        increase_mood(gp.size());
        for(auto i : gp){
            i->increase_mood(1);
        }
    }
};
