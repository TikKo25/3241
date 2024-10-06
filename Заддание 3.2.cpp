#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x) {
    return exp(x) * cos(exp(x) + 5) - 1;
}

int main() {
    double a = -3, b = 1, c, eps = 1e-9;
    int iterations = 0;

    // ���������, ���� �� ������ �� ������� [-3, 1]
    double fa = f(a), fb = f(b);
    if (fa == 0) {
        cout << "������ ��������� �� ������� �������: " << a << endl;
        return 0;
    }
    if (fb == 0) {
        cout << "������ ��������� �� ������� �������: " << b << endl;
        return 0;
    }

    // ���� ��������� ����������� � ����� ������� ���������
    while (b - a > eps) {
        c = (a + b) / 2;
        if (f(a) * f(c) < 0) {
            b = c;
        }
        else {
            a = c;
        }
    }
    c = (a + b) / 2;

    // �������� ������ ������� �������
    double fc = f(c);
    while (fabs(fc) > eps) {
        double x1 = a, x2 = b, f1 = f(x1), f2 = f(b);
        b = c;
        c = b - f(b) * (b - a) / (f(b) - f(a));
        a = x2;
        fc = f(c);
        iterations++;
    }

    cout << "����� ������ ��������� �� �������: 1" << endl;
    cout << "������� �������: [-3, 1]" << endl;
    cout << "����� ��������, ��������������� ��� ��������� �����: " << iterations << endl;
    cout << "�������� ���������� �����: " << fixed << setprecision(9) << c << endl;

    return 0;
}