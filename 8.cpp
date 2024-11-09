#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string matrix1, matrix2;

    std::cout << "Введите путь к первой матрице (matrix1.txt): ";
    std::cin >> matrix1;

    std::cout << "Введите путь ко второй матрице (matrix2.txt): ";
    std::cin >> matrix2;

    int rowsA, colsA, rowsB, colsB;

    std::ifstream fileA(matrix1);
    if (!fileA) {
        std::cerr << "Ошибка: не удалось открыть файл " << matrix1 << std::endl;
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

    std::ifstream fileB(matrix2);
    if (!fileB) {
        std::cerr << "Ошибка: не удалось открыть файл " << matrix2 << std::endl;
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

    if (rowsA != rowsB || colsA != colsB) {
        std::cerr << "Ошибка: размеры матриц не совпадают!" << std::endl;
        return 1;
    }

    int** C_add = new int* [rowsA];
    int** C_sub = new int* [rowsA];
    for (int i = 0; i < rowsA; ++i) {
        C_add[i] = new int[colsA];
        C_sub[i] = new int[colsA];
    }

    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsA; ++j) {
            C_add[i][j] = A[i][j] + B[i][j];
            C_sub[i][j] = A[i][j] - B[i][j];
        }
    }

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

    for (int i = 0; i < rowsA; ++i) {
        delete[] A[i];
        delete[] B[i];
        delete[] C_add[i];
        delete[] C_sub[i];
    }
    delete[] A;
    delete[] B;
    delete[] C_add;
    delete[] C_sub;

    return 0;
}
