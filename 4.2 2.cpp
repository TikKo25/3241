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
    bool isFirstLetterOfWord = true;

    for (int i = 0; i < input.length(); i++) {
        char c = input[i];
        if (isalpha(c)) {
            if (isFirstLetterOfWord) {
                result += c;
            }
            if (i == input.length() - 1 || !isalpha(input[i + 1])) {
                result += input[i];
                isFirstLetterOfWord = true;
            }
            else {
                isFirstLetterOfWord = false;
            }
        }
        else {
            isFirstLetterOfWord = true;
        }
    }

    cout << "ѕервый и последний символ каждого слова: " << result << endl;

    return 0;
}
