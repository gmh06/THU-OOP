#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

template<class T, int W> class AgentTrace;
template<class T, int W> ostream& operator<<(ostream& out, const AgentTrace<T, W>& src);

template <class T, int W>
class AgentTrace
{
public:
    struct Note
    {
        string r;
        T c;
        int t;
    };

    vector<Note> history;


    AgentTrace()
    {
        history.clear();
    }


    AgentTrace(const vector<string> &roles, const vector<T> &contents = vector<T>(), const vector<int> &tokens = vector<int>())
    {
        Note input;
        for(int i = 0; i < roles.size(); i ++){
            input.r = roles[i];

            if(contents.empty()){
                input.c = T();
            }else{
                input.c = contents[i];
            }

            if(tokens.empty()){
                input.t = 1;
            }else{
                input.t = tokens[i];
            }

            history.push_back(input);
        }
    }

    int add(const string &role, const T &content, int tokens = 1)
    {
        Note input;
        input.r = role;
        input.c = content;
        input.t = tokens;

        history.push_back(input);

        return history.size() - 1;
    }

    void set(int id, const T &content)
    {
        history[id].c = content;
    }

    T& get(int id)
    {
        return history[id].c;
    }

    vector<int> ids(const string &role) const
    {
        vector<int> ret;
        for(int i = 0; i < history.size(); i ++){
            if(history[i].r == role){
                ret.push_back(i);
            }
        }

        return ret;
    }

    int token_sum() const
    {
        int summ = 0;
        for(auto i : history){
            summ += i.t;
        }

        return summ;
    }

    bool operator==(const AgentTrace& oth)
    {
        if(history.size() != oth.history.size()){
            return false;
        }

        for(int i = 0; i < history.size(); i ++){
            if(history[i].r != oth.history[i].r){
                return false;
            }

            if(history[i].c != oth.history[i].c){
                return false;
            }

            if(history[i].t != oth.history[i].t){
                return false;
            }
        }

        return true;
    }

    bool operator!=(const AgentTrace& oth)
    {
        return !(*this == oth);
    }

    AgentTrace& operator=(const AgentTrace& oth)
    {
        history = oth.history;
        return *this;
    }

    friend ostream& operator<< <>(ostream& out, const AgentTrace<T, W>& src);
};

template<class T, int W>
ostream& operator<<(ostream& out, const AgentTrace<T, W>& src)
{
    for(int i = 0; i < src.history.size(); i ++){
        out << "#"
            << i
            << " ["
            << src.history[i].r
            << "] ("
            << src.history[i].t
            << ") "
            << src.history[i].c;

        if(i != src.history.size() - 1){
            out << endl;
        }
    }

    return out;
}