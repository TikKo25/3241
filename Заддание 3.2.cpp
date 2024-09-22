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

    // Определяем число корней на отрезке [a, b]
    if (fa * fb < 0) {
        cout << "Число корней уравнения на отрезке [" << a << "; " << b << "]: 1" << endl;
    }
    else {
        cout << "Число корней уравнения на отрезке [" << a << "; " << b << "]: 0" << endl;
        return 0;
    }

    // Используем метод секущих для уточнения корня
    double x0 = a, x1 = b;
    while (abs(fc) > epsilon) {
        double x2 = x1 - fc * (x1 - x0) / (fc - fa);
        x0 = x1;
        x1 = x2;
        fa = fc;
        fc = func(x2);
        iterations++;
    }

    cout << "Границы отрезка, выбранные для поиска корней: [" << a << "; " << b << "]" << endl;
    cout << "Число итераций, потребовавшихся для уточнения корня: " << iterations << endl;
    cout << "Значение найденного корня: " << setprecision(9) << x1 << endl;

    return 0;
}