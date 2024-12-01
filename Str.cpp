#include "Str.h"

Str::Str() : cstring(nullptr) {}

Str::Str(const char* str) {
    if (str) {
        size_t len = strlen(str);
        cstring = new char[len + 1];
        for (size_t i = 0; i < len; ++i) {
            cstring[i] = str[i];
        }
        cstring[len] = '\0';
    }
    else {
        cstring = nullptr;
    }
}

Str::Str(const Str& other) {
    if (other.cstring) {
        size_t len = strlen(other.cstring);
        cstring = new char[len + 1];
        for (size_t i = 0; i < len; ++i) {
            cstring[i] = other.cstring[i];
        }
        cstring[len] = '\0';
    }
    else {
        cstring = nullptr;
    }
}

Str& Str::operator=(const Str& other) {
    if (this != &other) {
        delete[] cstring;
        if (other.cstring) {
            size_t len = strlen(other.cstring);
            cstring = new char[len + 1];
            for (size_t i = 0; i < len; ++i) {
                cstring[i] = other.cstring[i];
            }
            cstring[len] = '\0';
        }
        else {
            cstring = nullptr;
        }
    }
    return *this;
}

Str::~Str() {
    delete[] cstring;
}

const char* Str::getValue() const {
    return cstring;
}

Str Str::operator+(const Str& other) const {
    Str result;
    if (cstring && other.cstring) {
        size_t len1 = strlen(cstring);
        size_t len2 = strlen(other.cstring);
        result.cstring = new char[len1 + len2 + 1];

        for (size_t i = 0; i < len1; ++i) {
            result.cstring[i] = cstring[i];
        }

        for (size_t i = 0; i < len2; ++i) {
            result.cstring[len1 + i] = other.cstring[i];
        }

        result.cstring[len1 + len2] = '\0';
    }
    else if (cstring) {
        result = *this;
    }
    else if (other.cstring) {
        result = other;
    }
    return result;
}

Str& Str::operator^=(bool isUpperCase) {
    if (isUpperCase && cstring) {
        for (size_t i = 0; i < strlen(cstring); ++i) {
            cstring[i] = toupper(cstring[i]);
        }
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Str& str) {
    if (str.getValue() == nullptr) {
        os << "(null)";
    }
    else {
        os << str.getValue();
    }
    return os;
}