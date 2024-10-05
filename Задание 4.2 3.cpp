#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string input;
    cout << "¬ведите строку (не более 30 символов, только от 'a' до 'z' и пробел): ";
    getline(cin, input);

    if (input.length() > 30) {
        cout << "ќшибка: строка не может быть длиннее 30 символов." << endl;
        return 1;
    }

    for (char c : input) {
        if (!islower(c) && c != ' ') {
            cout << "ќшибка: строка может содержать только символы от 'a' до 'z' и пробел." << endl;
            return 1;
        }
    }

    char searchChar;
    cout << "¬ведите символ (от 'a' до 'z'): ";
    cin >> searchChar;

    if (!islower(searchChar)) {
        cout << "ќшибка: введен неверный символ." << endl;
        return 1;
    }

    int count = 0;
    for (char c : input) {
        if (tolower(c) == tolower(searchChar)) {
            count++;
        }
    }

    cout << "—имвол '" << searchChar << "' встречаетс€ в строке " << count << " раз(а)." << endl;

    return 0;
}