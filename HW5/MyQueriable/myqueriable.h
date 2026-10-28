#pragma once

#include <vector>
#include <functional>

template <typename T>
class MyQueriable
{
private:
    std::vector<T> data;
public:
    MyQueriable<T>(const std::vector<T>& vec): data(vec) {}

    MyQueriable<T> where(std::function<bool(T)> f)
    {
        std::vector<T> filter;
        for (const auto& it : data)
        {
            if (f(it))
            {
                filter.push_back(it);
            }
        }

        return MyQueriable<T>(filter);
    }

    MyQueriable<T> apply(std::function<T(T)> f)
    {
        std::vector<T> image;
        for(const auto& it : data)
        {
            image.push_back(f(it));
        }

        return MyQueriable<T>(image);
    }

    T sum() const
    {
        T ret = 0;
        for(const auto& it : data)
        {
            ret += it;
        }

        return ret;
    }

    using iterator = typename std::vector<T>::iterator;

    iterator begin()
    {
        return data.begin();
    }

    iterator end()
    {
        return data.end();
    }
};

template <typename T>
MyQueriable<T> from(std::vector<T> vec)
{
    return MyQueriable<T>(vec);
}

template <typename T, unsigned N>
MyQueriable<T> from(T (&arr)[N])
{
    std::vector<T> vec(arr, arr + N);
    return MyQueriable<T>(vec);
}