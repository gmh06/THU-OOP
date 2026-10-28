#pragma once
#include <iostream>
using namespace std;

class Tester: public Agent
{
    char marker;
    int flag;
    int test_passed = 0;
public:
    Tester(int id, std::string& codes, char m, int f): Agent(id, codes), marker(m), flag(f) {}
    void action() override
    {
        int cnt = 0;
        for(auto ch : codes){
            if(ch == marker){
                cnt ++;
            }
        }

        if((cnt % 2) - (flag % 2) == 0){
            test_passed ++;
        }
    }

    void report() override
    {
        cout << "Tester "
             << get_agent_id()
             << ": "
             << test_passed
             << " tests passed"
             << endl;
    }
};