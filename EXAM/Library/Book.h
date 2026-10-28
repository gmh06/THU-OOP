#pragma once
#include <string>
#include <iostream>
using namespace std;

template <typename T>
class Book
{
    string author;
    T Pages;
    
    public:
    string name;
    Book(string n, string a, T P): name(n), author(a), Pages(P) {}

    void show()
    {
        cout << "Book name: "
             << name
             << ", Author: "
             << author
             << ", Pages: "
             << Pages
             << endl;
    }

    bool operator<(const Book<T>& other)
    {
        return Pages < other.Pages;
    }

};