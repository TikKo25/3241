#include <iostream>
#include <string>

using namespace std;

int main() {
    int num1, num2;
    char op;
    int result;

    cout << "Integer Calculator" << endl;
    cout << "Enter a number: ";
    cin >> num1;
    cout << "Enter the operation (+, -, *, /): ";
    cin >> op;
    cout << "Enter a number: ";
    cin >> num2;

    switch (op) {
    case '+':
        result = num1 + num2;
        cout << "Result: " << result << endl;
        break;
    case '-':
        result = num1 - num2;
        cout << "Result: " << result << endl;
        break;
    case '*':
        result = num1 * num2;
        cout << "Result: " << result << endl;
        break;
    case '/':
        if (num2 == 0) {
            cout << "Error: division by zero" << endl;
        }
        else {
            result = num1 / num2;
            cout << "Result: " << result << endl;
        }
        break;
    default:
        cout << "Error: undefined operation" << endl;
        break;
    }

    return 0;
}
