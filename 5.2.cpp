#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdexcept>

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
    case 4: case 6: case 9: case 11: return 30;
    case 2: return isLeapYear(year) ? 29 : 28;
    default: return 0; 
    }
}

bool parseDate(const std::string& dateStr, int& day, int& month, int& year) {
    char delimiter;
    std::istringstream dateStream(dateStr);

    if (dateStream >> day >> delimiter >> month >> delimiter >> year) {
        if (delimiter != '-' || day < 1 || month < 1 || year < 0) {
            return false;
        }

        if (month > 12 || day > daysInMonth(month, year)) {
            return false;
        }
        return true;
    }

    return false;
}

int countDaysBetween(int day1, int month1, int year1, int day2, int month2, int year2) {
    int totalDays = 0;
    if (year1 > year2 || (year1 == year2 && (month1 > month2 || (month1 == month2 && day1 > day2)))) {
        std::swap(day1, day2);
        std::swap(month1, month2);
        std::swap(year1, year2);
    }
    while (true) {
        totalDays++;
        day1++;
        if (day1 > daysInMonth(month1, year1)) {
            day1 = 1;
            month1++;
            if (month1 > 12) {
                month1 = 1;
                year1++;
            }
        }
        if (day1 == day2 && month1 == month2 && year1 == year2) {
            break;
        }
    }

    return totalDays;
}

void printHelp() {
    std::cout << "��������� ��� ���������� ���������� ���� ����� ����� ������." << std::endl;
    std::cout << "�������������:" << std::endl;
    std::cout << "1. �������� ���� � ������� ����-�����-��� ��� ���������:" << std::endl;
    std::cout << "   ./date_difference ����-�����-��� ����-�����-���" << std::endl;
    std::cout << "2. ������ ���� ��������������:" << std::endl;
    std::cout << "   ������� ������ ���� (����-�����-���):" << std::endl;
    std::cout << "   ������� ������ ���� (����-�����-���):" << std::endl;
    std::cout << "3. ��� ��������� ������� ������� �������:" << std::endl;
    std::cout << "   ./date_difference help" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc == 2 && std::string(argv[1]) == "help") {
        printHelp();
        return 0;
    }

    int day1, month1, year1, day2, month2, year2;

    if (argc == 3) {
        if (!parseDate(argv[1], day1, month1, year1) || !parseDate(argv[2], day2, month2, year2)) {
            std::cerr << "������: �������� ������ ���. ����������� ����-�����-���." << std::endl;
            return 1;
        }
    }
    else {
        std::string dateStr;
        std::cout << "������� ������ ���� (����-�����-���): ";
        std::cin >> dateStr;
        if (!parseDate(dateStr, day1, month1, year1)) {
                std::cerr << "������: �������� ������ ������ ����." << std::endl;
            return 1;
        }

        std::cout << "������� ������ ���� (����-�����-���): ";
        std::cin >> dateStr;
        if (!parseDate(dateStr, day2, month2, year2)) {
            std::cerr << "������: �������� ������ ������ ����." << std::endl;
            return 1;
        }
    }

    int daysDifference = countDaysBetween(day1, month1, year1, day2, month2, year2);
    std::cout << "���������� ���� ����� ������: " << daysDifference << " ����." << std::endl;

    return 0;
}
