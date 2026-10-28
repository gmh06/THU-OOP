#pragma once
#include <cstring>
#include <iostream>
using namespace std;

const int MAX = 220;
const int LIMIT = 1000000000;
class CHugeInt
{
    unsigned int content[23];
public:
    CHugeInt()
    {
        memset(content, 0, sizeof(content));
    }
    CHugeInt(const int input): CHugeInt()
    {
        if(input >= LIMIT){
            content[0] = input % LIMIT;
            content[1] = input / LIMIT;
        }else{
            content[0] = input;
        }
    }
    CHugeInt(const CHugeInt& input): CHugeInt()
    {
        (*this) = input;
    }
    CHugeInt(const char* input): CHugeInt()
    {
        int i = 0;
        for(; input[i] != '\0'; i ++);

        int first_len = i % 9;
        if(first_len == 0) first_len = 9;

        int ths_pos = (i + 8) / 9 - 1;
        int get = 0;

        for(i = 0; i < first_len; i ++){
            get = get * 10 + (input[i] - '0');
        }
        content[ths_pos] = get;
        get = 0;
        ths_pos --;

        for(; ths_pos >= 0; ths_pos --){
            for(int j = 0; j < 9; j ++){
                get = get * 10 + (input[i ++] - '0');
            }

            content[ths_pos] = get;
            get = 0;
        }
    }
    
    CHugeInt& operator+=(const int& input);
    friend CHugeInt operator+(const CHugeInt& t1, const int& t2);
    friend CHugeInt operator+(const int& t1, const CHugeInt& t2);
    CHugeInt& operator=(const CHugeInt& input);
    CHugeInt& operator++() { return *this += 1; }
    CHugeInt operator++(int)
    {
        CHugeInt ret = *this;
        ++ (*this);
        return ret;
    }
    CHugeInt operator+(const CHugeInt& input) const;
    friend std::ostream& operator<<(std::ostream& out, const CHugeInt& input);
};