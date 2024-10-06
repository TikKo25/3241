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

    // Проверяем, есть ли корень на отрезке [-3, 1]
    double fa = f(a), fb = f(b);
    if (fa == 0) {
        cout << "Корень уравнения на границе отрезка: " << a << endl;
        return 0;
    }
    if (fb == 0) {
        cout << "Корень уравнения на границе отрезка: " << b << endl;
        return 0;
    }

    // Ищем начальное приближение к корню методом дихотомии
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

    // Уточняем корень методом секущих
    double fc = f(c);
    while (fabs(fc) > eps) {
        double x1 = a, x2 = b, f1 = f(x1), f2 = f(b);
        b = c;
        c = b - f(b) * (b - a) / (f(b) - f(a));
        a = x2;
        fc = f(c);
        iterations++;
    }

    cout << "Число корней уравнения на отрезке: 1" << endl;
    cout << "Границы отрезка: [-3, 1]" << endl;
    cout << "Число итераций, потребовавшихся для уточнения корня: " << iterations << endl;
    cout << "Значение найденного корня: " << fixed << setprecision(9) << c << endl;

    return 0;
}