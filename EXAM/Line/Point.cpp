# include "Point.h"
# include <iostream>
using namespace std;

template <typename T>
void Point<T>::move(T dx, T dy)
{
    x += dx;
    y += dy;
}
template <typename T>
void Point<T>::show()
{
    cout << "(" << x << "," << y << ")" << endl;
}
template <typename T>
bool Point<T>::check(Line<T> const& l)
{
    T ys = l.k * x + l.b;

    if(isequal(ys, y)){
        return true;
    }

    return false;
}