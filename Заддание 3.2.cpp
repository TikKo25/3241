#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double func(double x) {
    return exp(x) * cos(exp(x) + 5) - 1;
}

int main() {
    double a = -3, b = 1, c = 0.07791, epsilon = 1e-9;
    double fa = func(a), fb = func(b), fc = func(c);
    int iterations = 0;

    // ���������� ����� ������ �� ������� [a, b]
    if (fa * fb < 0) {
        cout << "����� ������ ��������� �� ������� [" << a << "; " << b << "]: 1" << endl;
    }
    else {
        cout << "����� ������ ��������� �� ������� [" << a << "; " << b << "]: 0" << endl;
        return 0;
    }

    // ���������� ����� ������� ��� ��������� �����
    double x0 = a, x1 = b;
    while (abs(fc) > epsilon) {
        double x2 = x1 - fc * (x1 - x0) / (fc - fa);
        x0 = x1;
        x1 = x2;
        fa = fc;
        fc = func(x2);
        iterations++;
    }

    cout << "������� �������, ��������� ��� ������ ������: [" << a << "; " << b << "]" << endl;
    cout << "����� ��������, ��������������� ��� ��������� �����: " << iterations << endl;
    cout << "�������� ���������� �����: " << setprecision(9) << x1 << endl;

    return 0;
}