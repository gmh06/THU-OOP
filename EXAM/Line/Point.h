# pragma once
# include "Line.h"
template <typename T>
class Point
{
    T x;
    T y;

    bool isequal(const T& a, const T& b)
    {
        double diff = a - b;
        if(diff < 0)
            diff = - diff;

        return diff < 1e-6;
    }

public:
    Point(T x, T y): x(x), y(y) {}
    void move(T dx, T dy);
    void show();
    bool check(Line<T> const& l);
};