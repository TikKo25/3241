#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string input;
    cout << "������� ������ (�� ����� 50 ��������): ";
    getline(cin, input);

    if (input.length() > 50) {
        cout << "������: ������ �� ����� ���� ������� 50 ��������." << endl;
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

    cout << "������ ��������� ����� ������� �����: " << result << endl;

    return 0;
}