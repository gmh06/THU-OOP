# include "Line.h"
# include <iostream>
using namespace std;

template <typename T>
bool Line<T>::intersect(const Line& l)
{
    if(!isequal(k, l.k)){
        return true;
    }

    if(isequal(b, l.b)){
        return true;
    }

    return false;
}

template <typename T>
void Line<T>::show()
{
    cout << k << "," << b << endl;
    return;
}
template <typename T>
bool Line<T>::operator<(const Line& l)
{
    if(isequal(k, l.k)){
        return false;
    }

    if(k < l.k){
        return true;
    }

    return false;
}