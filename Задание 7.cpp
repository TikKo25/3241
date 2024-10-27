#include <iostream>
#include <random>
#include <limits>

const char empty = ' ';
const char fill = '+';

void ff(char* mat, int n, int m, int x, int y, char fillSymbol) {
    if (x >= 0 && x < n && y >= 0 && y < m && mat[x * m + y] == empty) {
        mat[x * m + y] = fillSymbol;
        ff(mat, n, m, x, y + 1, fillSymbol);
        ff(mat, n, m, x, y - 1, fillSymbol);
        ff(mat, n, m, x + 1, y, fillSymbol);
        ff(mat, n, m, x - 1, y, fillSymbol);
    }
}

void printMatrix(char* mat, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << mat[i * m + j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void a(char* mat, int n, int m, int& e, int& fc, int& b) {
    e = 0;
    fc = 0;
    b = 0;

    for (int i = 0; i < n * m; i++) {
        if (mat[i] == empty) {
            e++;
        }
        else if (mat[i] == fill) {
            fc++;
        }
        else {
            b++;
        }
    }
}

template <typename T>
bool check(T& value) {
    std::cin >> value;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "rus");
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 10);
    int n, m, b;
    char f;

    std::cout << " Put length of matrix (n, m): ";
    while (!check(n) || !check(m)) {
        std::cout << "Error.Please,put two counts : ";
    }

    std::cout << "Variation of block: ";
    while (!check(b)) {
        std::cout << "Error. Please, put one count: ";
    }

    std::cout << "Enter the character to fill in: ";
    std::cin >> f;

    char* mat = new char[n * m];
    for (int i = 0; i < n * m; i++) {
        mat[i] = empty;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dis(gen) < b) {
                mat[i * m + j] = fill;
            }
        }
    }

    std::cout << "Source matrix:" << std::endl;
    printMatrix(mat, n, m);

    int x, y;
    std::cout << " Enter coordinates (x, y) to start filling: ";
    while (!check(x) || !check(y) || x < 0 || x >= n || y < 0 || y >= m) {
        std::cout << "Input error. Please enter the correct coordinates (x, y): ";
    }

    if (mat[x * m + y] == fill) {
        std::cout << "The cell with the block is selected, filling is not possible." << std::endl;
        delete[] mat;
        return 1;
    }

    ff(mat, n, m, x, y, f);

    std::cout << "Matrix after filling:" << std::endl;
    printMatrix(mat, n, m);

    int emptyCount, fillCount, blockCount;
    a(mat, n, m, emptyCount, fillCount, blockCount);
    std::cout << "Empty cells: " << emptyCount << std::endl;
    std::cout << "Number of fillings: " << fillCount << std::endl;
    std::cout << "Blocked cells: " << blockCount << std::endl;

    delete[] mat;
    return 0;
}
