# pragma once
# include <cmath>

template <typename T>
class Line
{
    
    bool isequal(const T& a, const T& b)
    {
        double diff = a - b;
        if(diff < 0)
        diff = - diff;
        
        return diff < 1e-6;
    }
    
public:

    T k;
    T b;
    Line(T k, T b = 0): k(k), b(b) {}
    bool intersect(const Line& l);
    void show();
    bool operator<(const Line& l);
};