#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>

void sortArray(double* arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

double calculateMean(double* arr, int size) {
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum / size;
}

double calculateMedian(double* arr, int size) {
    if (size % 2 == 0) {
        return (arr[size / 2 - 1] + arr[size / 2]) / 2;
    }
    else {
        return arr[size / 2];
    }
}

double calculateStdDev(double* arr, int size, double mean) {
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += (arr[i] - mean) * (arr[i] - mean);
    }
    return std::sqrt(sum / size);
}

bool isValidNumber(const char* str) {
    char* endPtr;
    std::strtod(str, &endPtr);
    return *endPtr == '\0'; // Проверяем, что весь ввод был преобразован
}

int main() {
    const int MAX_SIZE = 100; // Максимальный размер массива
    double* values = new double[MAX_SIZE];
    int count = 0;

    std::cout << "Введите числа (введите 'q' для завершения ввода):" << std::endl;

    char input[256];
    while (count < MAX_SIZE) {
        std::cin >> input;
        if (std::strcmp(input, "q") == 0) {
            break; // Выход при вводе 'q'
        }
        if (!isValidNumber(input)) {
            std::cerr << "Ошибка: '" << input << "' не является числом." << std::endl;
            continue; // Пропускаем неправильный ввод
        }
        values[count++] = std::atof(input); // Сохраняем введённое число
    }

    // Сортировка массива
    sortArray(values, count);

    // Вычисление статистических значений
    double mean = calculateMean(values, count);
    double median = calculateMedian(values, count);
    double stdDev = calculateStdDev(values, count, mean);
    double min = values[0];
    double max = values[count - 1];

    // Вывод результатов
    std::cout << "Количество введенных значений: " << count << std::endl;
    if (count > 62) {
        std::cout << "Дальнейшая длина массива не указывается." << std::endl;
    }
    std::cout << "Отсортированные значения: ";
    for (int i = 0; i < count; ++i) {
        std::cout << values[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Среднее: " << std::setprecision(4) << mean << std::endl;
    std::cout << "Медиана: " << median << std::endl;
    std::cout << "Среднеквадратичное отклонение: " << std::setprecision(4) << stdDev << std::endl;
    std::cout << "Минимальное значение: " << min << std::endl;
    std::cout << "Максимальное значение: " << max << std::endl;

    // Освобождение памяти
    delete[] values;

    return 0;
}
