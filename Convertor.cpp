#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    int num;
    char system;

    cout << "Enter a number: ";
    cin >> num;

    cout << "Change the system (d - decimal b - binar): ";
    cin >> system;

    if (system == 'd') {
        cout << "In the decimal system: " << num << endl;

        cout << "In the binar system: ";
        for (int i = 31; i >= 0; i--) {
            cout << ((num >> i) & 1);
        }
        cout << endl;
    }
    else if (system == 'b') {
        cout << "In the binar system: ";
        for (int i = 31; i >= 0; i--) {
            cout << ((num >> i) & 1);
        }
        cout << endl;

        cout << "In the decimal system: " << num << endl;
    }
    else {
        cout << "Invalid change" << endl;
    }

    return 0;
}