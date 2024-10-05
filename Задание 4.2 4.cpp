#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string str1, str2;

    cout << "Введите первую строку (не более 50 символов): ";
    getline(cin, str1);
    if (str1.length() > 50) {
        cout << "Ошибка: первая строка не может быть длиннее 50 символов." << endl;
        return 1;
    }

    cout << "Введите вторую строку (не более 50 символов): ";
    getline(cin, str2);
    if (str2.length() > 50) {
        cout << "Ошибка: вторая строка не может быть длиннее 50 символов." << endl;
        return 1;
    }

    int index = -1;
    for (int i = 0; i <= str1.length() - str2.length(); i++) {
        bool found = true;
        for (int j = 0; j < str2.length(); j++) {
            if (tolower(str1[i + j]) != tolower(str2[j])) {
                found = false;
                break;
            }
        }
        if (found) {
            index = i;
            break;
        }
    }

    cout << "Индекс вхождения второй строки в первую: " << index << endl;

    return 0;
}