#pragma once
#include <vector>
#include <string>
#include "Book.h"
using namespace std;

template <typename T>
class Library
{
    vector<Book<T>> lib;

    public:

    void addBook(const Book<T>& book)
    {
        lib.push_back(book);
    }

    void show()
    {
        for(auto book : lib)
        {
            book.show();
        }
    }

    void borrowBook(const std::string& title)
    {
        bool isthere = false;

        for(auto book : lib)
        {
            if(book.name == title){
                isthere = true;
                break;
            }
        }

        if(isthere){
            cout << "Books Checked out " << title << "." << endl;

        }else{
            cout << "Book " << title << " does not exist." << endl;
        }
    }
};