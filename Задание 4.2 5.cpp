#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string str1, str2;

    cout << "������� ������ ������ (�� ����� 50 ��������): ";
    getline(cin, str1);
    if (str1.length() > 50) {
        cout << "������: ������ ������ �� ����� ���� ������� 50 ��������." << endl;
        return 1;
    }

    cout << "������� ������ ������ (�� ����� 50 ��������): ";
    getline(cin, str2);
    if (str2.length() > 50) {
        cout << "������: ������ ������ �� ����� ���� ������� 50 ��������." << endl;
        return 1;
    }

    int count = 0;
    int i = 0;
    do {
        int j = 0;
        while (i < str1.length() && j < str2.length() && tolower(str1[i]) == tolower(str2[j])) {
            i++;
            j++;
        }
        if (j == str2.length()) {
            count++;
        }
        i++;
    } while (i <= str1.length() - str2.length());

    cout << "���������� ��������� ������ ������ � ������: " << count << endl;

    return 0;
}