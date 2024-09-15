#include <iostream>

int main() {
    long long int a = 1, b = 2, c, sum = 2;  

    while (b <= 4000000) {  
        c = a + b;  
        a = b;
        b = c;

        if (b % 2 == 0) {  
            sum += b;
        }
    }

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}