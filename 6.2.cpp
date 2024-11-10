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
    return *endPtr == '\0'; // ���������, ��� ���� ���� ��� ������������
}

int main() {
    const int MAX_SIZE = 100; // ������������ ������ �������
    double* values = new double[MAX_SIZE];
    int count = 0;

    std::cout << "������� ����� (������� 'q' ��� ���������� �����):" << std::endl;

    char input[256];
    while (count < MAX_SIZE) {
        std::cin >> input;
        if (std::strcmp(input, "q") == 0) {
            break; // ����� ��� ����� 'q'
        }
        if (!isValidNumber(input)) {
            std::cerr << "������: '" << input << "' �� �������� ������." << std::endl;
            continue; // ���������� ������������ ����
        }
        values[count++] = std::atof(input); // ��������� �������� �����
    }

    // ���������� �������
    sortArray(values, count);

    // ���������� �������������� ��������
    double mean = calculateMean(values, count);
    double median = calculateMedian(values, count);
    double stdDev = calculateStdDev(values, count, mean);
    double min = values[0];
    double max = values[count - 1];

    // ����� �����������
    std::cout << "���������� ��������� ��������: " << count << std::endl;
    if (count > 62) {
        std::cout << "���������� ����� ������� �� �����������." << std::endl;
    }
    std::cout << "��������������� ��������: ";
    for (int i = 0; i < count; ++i) {
        std::cout << values[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "�������: " << std::setprecision(4) << mean << std::endl;
    std::cout << "�������: " << median << std::endl;
    std::cout << "������������������ ����������: " << std::setprecision(4) << stdDev << std::endl;
    std::cout << "����������� ��������: " << min << std::endl;
    std::cout << "������������ ��������: " << max << std::endl;

    // ������������ ������
    delete[] values;

    return 0;
}
