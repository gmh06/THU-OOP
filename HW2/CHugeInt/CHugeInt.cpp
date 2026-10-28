#include "CHugeInt.h"
#include <iomanip>

CHugeInt& CHugeInt::operator=(const CHugeInt& input)
{
    for(int i = 0; i < 23; i++){
        content[i] = input.content[i];
    }
    return *this;
}

CHugeInt& CHugeInt::operator+=(const int& input)
{
    long long now_add = input;
    int i = 0;
    for(; now_add + content[i] >= LIMIT; i ++){
        long long now_result = now_add + content[i];
        content[i] = now_result % LIMIT;
        now_add = now_result / LIMIT;
    }

    content[i] += now_add;

    return *this;
}

CHugeInt operator+(const CHugeInt& t1, const int& t2)
{
    CHugeInt ret = t1;
    ret += t2;
    return ret;
}

CHugeInt operator+(const int& t1, const CHugeInt& t2)
{
    CHugeInt ret = t2;
    ret += t1;
    return ret;
}

CHugeInt CHugeInt::operator+(const CHugeInt& input) const
{
    CHugeInt ret;
    int extra = 0;
    int result = 0;
    for(int i = 0; i < 23; i ++){
        result = content[i] + input.content[i] + extra;
        extra = result / LIMIT;
        ret.content[i] = result % LIMIT;
    }

    return ret;
}

std::ostream& operator<<(std::ostream& out, const CHugeInt& input)
{
    int i = 22;
    for(; input.content[i] == 0 && i > 0; i --);

    out << input.content[i];

    for(i --; i >= 0; i --){
        out << std::setw(9) << std::setfill('0') << input.content[i];
    }

    out << std::setfill(' ');

    return out;
}