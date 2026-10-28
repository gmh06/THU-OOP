#pragma once
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

template<class T>
struct AgentRecord {
    int id;
    string role;
    T content;
    int tokens;
};

template<class T, int W>
class AgentTrace {
public:
    vector<AgentRecord<T>> history;

    AgentTrace()
    {
        history.clear();
    }

    AgentTrace(const vector<string>& roles,
               const vector<T>& contents = vector<T>(),
               const vector<int>& tokens = vector<int>())
    {
        AgentRecord<T> input;
        for(int i = 0; i < roles.size(); i ++){
            input.role = roles[i];

            if(contents.empty()){
                input.content = T();
            }else{
                input.content = contents[i];
            }

            if(tokens.empty()){
                input.tokens = 1;
            }else{
                input.tokens = tokens[i];
            }

            history.push_back(input);
        }

    }

    int add(const string& role, const T& content, int tokens = 1)
    {
        AgentRecord<T> input;
        input.role = role;
        input.content = content;
        input.tokens = tokens;

        history.push_back(input);

        return history.size() - 1;
    }  

    void set(int id, const T& content)
    {
        history[id].content = content;
    }

    T& get(int id)
    {
        return history[id].content;
    }

    vector<int> ids(const string& role) const
    {
        vector<int> ret;
        for(int i = 0; i < history.size(); i ++){
            if(history[i].role == role){
                ret.push_back(i);
            }
        }

        return ret;
    }

    int token_sum() const
    {
        int summ = 0;
        for(auto i : history){
            summ += i.tokens;
        }

        return summ;
    }

    bool operator==(const AgentTrace& other) const
    {
        if(history.size() != other.history.size()){
            return false;
        }

        for(int i = 0; i < history.size(); i ++){
            if(history[i].role != other.history[i].role){
                return false;
            }

            if(history[i].content != other.history[i].content){
                return false;
            }

            if(history[i].tokens != other.history[i].tokens){
                return false;
            }
        }

        return true;
    }

    bool operator!=(const AgentTrace& other) const
    {
        return !(*this == other);
    }

    AgentTrace& operator=(const AgentTrace& other)
    {
        history = other.history;
        return *this;
    }

    class Iterator {
    public:
        AgentRecord<T>* it;

        Iterator(AgentRecord<T>* it): it(it) {}

        T& operator*() const
        {
            return it->content;
        }

        Iterator& operator++()
        {
            it ++;
            return *this;
        }
        Iterator operator++(int)
        {
            Iterator temp(this->it);
            it ++;
            return temp;
        }

        bool operator==(const Iterator& other) const
        {
            return it == other.it;
        }

        bool operator!=(const Iterator& other) const
        {
            return !(*this == other);
        }
        Iterator& operator=(const Iterator& other)
        {
            it = other.it;
            return *this;
        }
    };

    Iterator begin()
    {
        return Iterator(&(history[0]));
    }

    Iterator end()
    {
        return Iterator(&(history[history.size() - 1]) + 1);
    }

    T& operator[](int id)
    {
        return history[id].content;
    }

    class RoleView {
    public:
        vector<AgentRecord<T>*> rolehis;

        T& operator[](int index)
        {
            return rolehis[index]->content;
        }
    };

    RoleView operator[](const string& role)
    {
        RoleView rv;

        for(int i = 0; i < history.size(); i ++){
            if(history[i].role == role){
                rv.rolehis.push_back(&(history[i]));
            }
        }

        return rv;
    }

    void compact();

    template<class ScoreFunc>
    vector<T> retrieve(int k, ScoreFunc score) const;

    map<string, int> tool_stats() const;
};

template<class T, int W>
ostream& operator<<(ostream& os, const AgentTrace<T, W>& trace)
{
    for(int i = 0; i < trace.history.size(); i ++){
        os << "#"
           << i
           << " ["
           << trace.history[i].role
           << "] ("
           << trace.history[i].tokens
           << ") "
           << trace.history[i].content;

        if(i != trace.history.size() - 1){
            os << endl;
        }
    }

    return os;
}
