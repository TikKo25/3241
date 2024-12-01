#ifndef STR_H
#define STR_H

#include <iostream>
#include <cstring> 

class Str {
private:
    char* cstring;

public:
    Str();
    Str(const char* str);
    Str(const Str& other);
    Str& operator=(const Str& other);
    ~Str();

    const char* getValue() const;

    Str operator+(const Str& other) const;

    Str& operator^=(bool isUpperCase);

    friend std::ostream& operator<<(std::ostream& os, const Str& str);
};