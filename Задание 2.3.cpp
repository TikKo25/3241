#include <iostream>
#include <string>

std::string getSeasonByMonth(int month) {
    if (month >= 3 && month <= 5) {
        return "spring";
    }
    else if (month >= 6 && month <= 8) {
        return "summer";
    }
    else if (month >= 9 && month <= 11) {
        return "autumn";
    }
    else {
        return "winter";
    }
}

int main() {
    int monthNumber;
    std::cout << "Month'es number (1-12): ";
    std::cin >> monthNumber;

    std::string season = getSeasonByMonth(monthNumber);
    std::cout << "Season: " << season << std::endl;

    return 0;
}