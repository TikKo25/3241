#include <iostream>
#include "Str.h"

int main() {
    Str str1("Hello");
    Str str2(" World");

    Str result = str1 + str2;

    std::cout << "Result of addition: " << result << std::endl;

    result ^= true;

    std::cout << "Result after conversion to uppercase: " << result << std::endl;

    return 0;
}