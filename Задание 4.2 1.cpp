#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string input;
    cout << "¬ведите строку (не более 50 символов): ";
    getline(cin, input);

    if (input.length() > 50) {
        cout << "ќшибка: строка не может быть длиннее 50 символов." << endl;
        return 1;
    }

    string result;
    bool isFirstLetter = true;

    for (char c : input) {
        if (isalpha(c)) {
            if (isFirstLetter) {
                result += toupper(c);
                isFirstLetter = false;
            }
        }
        else {
            isFirstLetter = true;
        }
    }

    cout << "ѕервые заглавные буквы каждого слова: " << result << endl;

    return 0;
}