#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string input;
    cout << "������� ������ (�� ����� 30 ��������, ������ �� 'a' �� 'z' � ������): ";
    getline(cin, input);

    if (input.length() > 30) {
        cout << "������: ������ �� ����� ���� ������� 30 ��������." << endl;
        return 1;
    }

    for (char c : input) {
        if (!islower(c) && c != ' ') {
            cout << "������: ������ ����� ��������� ������ ������� �� 'a' �� 'z' � ������." << endl;
            return 1;
        }
    }

    char searchChar;
    cout << "������� ������ (�� 'a' �� 'z'): ";
    cin >> searchChar;

    if (!islower(searchChar)) {
        cout << "������: ������ �������� ������." << endl;
        return 1;
    }

    int count = 0;
    for (char c : input) {
        if (tolower(c) == tolower(searchChar)) {
            count++;
        }
    }

    cout << "������ '" << searchChar << "' ����������� � ������ " << count << " ���(�)." << endl;

    return 0;
}