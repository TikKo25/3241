#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int getDaysBetweenDates(int day1, int month1, int year1, int day2, int month2, int year2) {
    int days1 = (year1 - 1) * 365 + (year1 - 1) / 4 - (year1 - 1) / 100 + (year1 - 1) / 400 + (30 * (month1 - 1) + (month1 > 2 ? (year1 % 4 == 0 && (year1 % 100 != 0 || year1 % 400 == 0) ? 1 : 0) : 0) + day1);

    int days2 = (year2 - 1) * 365 + (year2 - 1) / 4 - (year2 - 1) / 100 + (year2 - 1) / 400 + (30 * (month2 - 1) + (month2 > 2 ? (year2 % 4 == 0 && (year2 % 100 != 0 || year2 % 400 == 0) ? 1 : 0) : 0) + day2);

    return days2 - days1;
}

bool getDate(int& day, int& month, int& year) {
    cout << "Enter data ÄÄ-ÌÌ-ÃÃÃÃ: ";
    string input;
    getline(cin, input);

    vector<string> parts;
    string token;
    stringstream ss(input);

    while (getline(ss, token, '-')) {
        parts.push_back(token);
    }

    if (parts.size() != 3) {
        cerr << "Error." << endl;
        return false;
    }

    day = stoi(parts[0]);
    month = stoi(parts[1]);
    year = stoi(parts[2]);

    return true;
}
bool isValidDate(int day, int month, int year) {
    if (year < 1 || month < 1 || month > 12 || day < 1) {
        return false;
    }

    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (month == 2) {
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
            if (day > 29) {
                return false;
            }
        }
        else if (day > 28) {
            return false;
        }
    }
    else if (day > daysInMonth[month - 1]) {
        return false;
    }

    return true;
}

int main() {
    int day1, month1, year1, day2, month2, year2;

    if (!getDate(day1, month1, year1) || !getDate(day2, month2, year2)) {
        return 1;
    }

    int daysBetween = getDaysBetweenDates(day1, month1, year1, day2, month2, year2);
    cout << "Count of days " << day1 << "-" << month1 << "-" << year1 << " è " << day2 << "-" << month2 << "-" << year2 << " : " << daysBetween << endl;

    return 0;
}