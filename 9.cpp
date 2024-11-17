#include <iostream>
#include <vector>
#include <tuple>
#include <fstream>
#include <stdexcept>

template<typename T>
class SparseMatrix {
public:
    SparseMatrix(size_t rows, size_t cols) : rows(rows), cols(cols) {}

    void set(size_t r, size_t c, T value) {
        if (r >= rows || c >= cols) {
            throw std::out_of_range("Index out of bounds");
        }
        if (value != T()) {
            data.emplace_back(r, c, value);
        }
    }

    T get(size_t r, size_t c) const {
        if (r >= rows || c >= cols) {
            throw std::out_of_range("Index out of bounds");
        }
        for (const auto& element : data) {
            if (std::get<0>(element) == r && std::get<1>(element) == c) {
                return std::get<2>(element);
            }
        }
        return T(); // Возврат нулевого значения, если элемент не найден
    }

    std::tuple<T, size_t, size_t> findMin() const {
        if (data.empty()) {
            throw std::runtime_error("Matrix is empty");
        }

        size_t minRow = std::get<0>(data[0]);
        size_t minCol = std::get<1>(data[0]);
        T minValue = std::get<2>(data[0]);

        for (size_t i = 1; i < data.size(); ++i) {
            size_t row = std::get<0>(data[i]);
            size_t col = std::get<1>(data[i]);
            T value = std::get<2>(data[i]);

            if (value < minValue) {
                minValue = value;
                minRow = row;
                minCol = col;
            }
        }

        return std::make_tuple(minValue, minRow, minCol);
    }

    std::tuple<T, size_t, size_t> findMax() const {
        if (data.empty()) {
            throw std::runtime_error("Matrix is empty");
        }

        size_t maxRow = std::get<0>(data[0]);
        size_t maxCol = std::get<1>(data[0]);
        T maxValue = std::get<2>(data[0]);

        for (size_t i = 1; i < data.size(); ++i) {
            size_t row = std::get<0>(data[i]);
            size_t col = std::get<1>(data[i]);
            T value = std::get<2>(data[i]);

            if (value > maxValue) {
                maxValue = value;
                maxRow = row;
                maxCol = col;
            }
        }

        return std::make_tuple(maxValue, maxRow, maxCol);
    }

    void loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) {
            throw std::runtime_error("Unable to open file");
        }

        size_t r, c;
        T value;
        while (file >> r >> c >> value) {
            set(r, c, value);
        }

        file.close();
    }

    void saveToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (!file) {
            throw std::runtime_error("Unable to open file");
        }

        for (const auto& element : data) {
            file << std::get<0>(element) << " " << std::get<1>(element) << " " << std::get<2>(element) << "\n";
        }

        file.close();
    }

private:
    size_t rows;
    size_t cols;
    std::vector<std::tuple<size_t, size_t, T>> data;
};

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <output_file>\n";
        return 1;
    }

    const std::string inputFile = argv[1];
    const std::string outputFile = argv[2];

    try {
            SparseMatrix<int> matrix(10, 10); 
        matrix.loadFromFile(inputFile);
        std::tuple<int, size_t, size_t> minResult = matrix.findMin();
        int minValue = std::get<0>(minResult);
        size_t minRow = std::get<1>(minResult);
        size_t minCol = std::get<2>(minResult);
        std::cout << "Min value: " << minValue << " at (" << minRow << ", " << minCol << ")\n";

        std::tuple<int, size_t, size_t> maxResult = matrix.findMax();
        int maxValue = std::get<0>(maxResult);
        size_t maxRow = std::get<1>(maxResult);
        size_t maxCol = std::get<2>(maxResult);
        std::cout << "Max value: " << maxValue << " at (" << maxRow << ", " << maxCol << ")\n";

        matrix.saveToFile(outputFile);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}