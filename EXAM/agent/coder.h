#pragma once
#include <iostream>
using namespace std;

class Coder: public Agent
{
    int char_coded;
public:
    Coder(int id, std::string& codes): Agent(id, codes), char_coded(0) {}
    void action() override
    {
        string input = "";
        cin >> input;
        
        codes += input;
        char_coded += input.size();
    }

    void report() override
    {
        cout << "Coder "
             << get_agent_id()
             << ": "
             << char_coded
             << " characters coded"
             << endl;
    }
};