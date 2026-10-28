#include "agent.h"
#include "coder.h"
#include "tester.h"

Agent* Agent::create_agent(int agent_type, int id, std::string& codes)
{
    Agent* ag;
    if(agent_type == 0){
        ag = new Coder(id, codes);
    }else{
        char m;
        int f;
        cin >> m >> f;
        ag = new Tester(id, codes, m, f);
    }

    return ag;
}
