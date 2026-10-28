#pragma once

#include<string>

class PalString
{
    private:
    char* content;
    int _size;
    
    void initial(const char* input)
    {
        _size = std::string(input).size();
        content = new char[_size * 2 + 1];
        for(int i = 0; i < _size; i ++){
            content[i] = input[i];
        }
        for(int i = 0; i < _size; i ++){
            content[_size + i] = input[_size - 1 - i];
        }
        content[_size * 2] = '\0';
    }
    
    void initial_between(const PalString& other)
    {
        _size = other._size;
        content = new char[_size * 2 + 1];
        for(int i = 0; i < _size; i ++){
            content[i] = other.content[i];
        }
        for(int i = 0; i < _size; i ++){
            content[_size + i] = other.content[_size - 1 - i];
        }
        content[_size * 2] = '\0';
    }

public:

    PalString(const char* input) { initial(input); }
    PalString(const PalString& other)
    {
        initial_between(other);
    }
    ~PalString()
    {
        delete[] content;
    }
    PalString& operator=(const PalString& other)
    {
        if (this != &other) {
            delete[] content;
            initial_between(other);
        }
        return *this;
    }
    char* getString() const
    {
        return content;
    }
    void changeString(const char* input)
    {
        delete[] content;
        initial(input);
    }


    friend std::ostream& operator<<(std::ostream& out, const PalString& palstring);
};

std::ostream& operator<<(std::ostream& out, const PalString& palstring)
{
    out << palstring.getString();
    return out;
}