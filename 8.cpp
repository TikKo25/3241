#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename1, filename2;

    // Запрос команд у пользователя
    std::cout << "Введите путь к первой матрице (matrix1.txt): ";
    std::cin >> filename1;

    std::cout << "Введите путь ко второй матрице (matrix2.txt): ";
    std::cin >> filename2;

    int rowsA, colsA, rowsB, colsB;

    // Чтение первой матрицы
    std::ifstream fileA(filename1);
    if (!fileA) {
        std::cerr << "Ошибка: не удалось открыть файл " << filename1 << std::endl;
        return 1;
    }

    fileA >> rowsA >> colsA;
    int** A = new int* [rowsA];
    for (int i = 0; i < rowsA; ++i) {
        A[i] = new int[colsA];
        for (int j = 0; j < colsA; ++j) {
            fileA >> A[i][j];
        }
    }
    fileA.close();

    // Чтение второй матрицы
    std::ifstream fileB(filename2);
    if (!fileB) {
        std::cerr << "Ошибка: не удалось открыть файл " << filename2 << std::endl;
        // Освобождение памяти
        for (int i = 0; i < rowsA; ++i) {
            delete[] A[i];
        }
        delete[] A;
        return 1;
    }

    fileB >> rowsB >> colsB;
    int** B = new int* [rowsB];
    for (int i = 0; i < rowsB; ++i) {
        B[i] = new int[colsB];
        for (int j = 0; j < colsB; ++j) {
            fileB >> B[i][j];
        }
    }
    fileB.close();

    // Проверка совместимости размеров матриц
    if (rowsA != rowsB || colsA != colsB) {
        std::cerr << "Ошибка: размеры матриц не совпадают!" << std::endl;

        // Освобождение памяти
        for (int i = 0; i < rowsA; ++i) {
            delete[] A[i];
        }
        delete[] A;
        for (int i = 0; i < rowsB; ++i) {
            delete[] B[i];
        }
        delete[] B;
        return 1;
    }

    // Создаем матрицы для результатов
    int** C_add = new int* [rowsA];
    int** C_sub = new int* [rowsA];
    for (int i = 0; i < rowsA; ++i) {
        C_add[i] = new int[colsA];
        C_sub[i] = new int[colsA];
    }

    // Сложение и вычитание матриц
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsA; ++j) {
            C_add[i][j] = A[i][j] + B[i][j];
            C_sub[i][j] = A[i][j] - B[i][j];
        }
    }

    // Вывод результатов сложения и вычитания
    std::cout << "Результат сложения матриц:" << std::endl;
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsA; ++j) {
            std::cout << C_add[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Результат вычитания матриц:" << std::endl;
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsA; ++j) {
            std::cout << C_sub[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Освобождение памяти
    for (int i = 0; i < rowsA; ++i) {
        delete[] A[i];
        delete[] C_add[i];
        delete[] C_sub[i];
    }
    delete[] A;
    delete[] C_add;
    delete[] C_sub;

    for (int i = 0; i < rowsB; ++i) {
        delete[] B[i];
    }
    delete[] B;

    return 0;
}