#ifndef STR_H
#define STR_H

#include <iostream>
#include <algorithm>
#include <cstring>

class Str {
private:
    char* cstring;

public:
    Str() : cstring(nullptr) {}
    Str(const char* cstr);
    Str(const Str& other);
    Str& operator=(const Str& other);
    Str operator+(const Str& other) const;
    Str& operator^();
    operator const char* () const;
    ~Str();
    void print() const;
};

#endif 

//Str.cpp

#include "Str.h"
Str::Str(const char* cstr) {
    size_t n = std::strlen(cstr) + 1; 
    cstring = new char[n]; 
    std::copy(cstr, cstr + n, cstring); 
}
Str::Str(const Str& other) {
    size_t n = std::strlen(other.cstring);
    cstring = new char[n + 1]; 
    std::copy(other.cstring, other.cstring + n, cstring); 
    cstring[n] = 0;
}

Str& Str::operator=(const Str& other) {
    if (this == &other) 
        return *this;

    size_t n = std::strlen(other.cstring) + 1; 
    char* new_cstring = new char[n]; 
    std::copy(other.cstring, other.cstring + n, new_cstring);

    delete[] cstring; 
    cstring = new_cstring; 
    return *this;
}

Str Str::operator+(const Str& other) const {
    size_t n1 = std::strlen(cstring);
    size_t n2 = std::strlen(other.cstring);
    Str result;
    result.cstring = new char[n1 + n2 + 1];

    std::copy(cstring, cstring + n1, result.cstring);
    std::copy(other.cstring, other.cstring + n2, result.cstring + n1);
    result.cstring[n1 + n2] = '\0';

    return result; 
}

Str& Str::operator^() {
    for (size_t i = 0; cstring[i]; i++) {
        if (cstring[i] >= 'a' && cstring[i] <= 'z') {
            cstring[i] = cstring[i] - 'a' + 'A'; 
        }
    }
    return *this;
}

Str::operator const char* () const {
    return cstring;
}

Str::~Str() {
    delete[] cstring; 
}

void Str::print() const {
    std::cout << cstring << std::endl;
}
//main.cpp

#include "Str.h"

int main() {
    Str str1("H ");
    Str str2("W");

    Str str3 = str1 + str2;
    str3.print();
        str3 ^ ();

    str3.print(); 

    return 0;
}