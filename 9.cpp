#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <stdexcept>
#include <string>

template <typename T>
class SparseMatrix {
public:
    SparseMatrix(size_t rows, size_t cols) : rows_(rows), cols_(cols) {}

    void insert(size_t r, size_t c, T value) {
        if (value != 0) {
            elements_.emplace_back(r, c, value);
        }
    }

    T get(size_t r, size_t c) const {
        if (r >= rows_ || c >= cols_) {
            throw std::out_of_range("Index out of range");
        }
        for (size_t i = 0; i < elements_.size(); ++i) {
            if (std::get<0>(elements_[i]) == r && std::get<1>(elements_[i]) == c) {
                return std::get<2>(elements_[i]);
            }
        }
        return T();
    }

    std::tuple<T, std::tuple<size_t, size_t>, T, std::tuple<size_t, size_t>> minMax() const {
        if (elements_.empty()) {
            throw std::runtime_error("Matrix has no elements");
        }

        T minValue = std::get<2>(elements_[0]);
        T maxValue = std::get<2>(elements_[0]);
        std::tuple<size_t, size_t> minIndex = { std::get<0>(elements_[0]), std::get<1>(elements_[0]) };
        std::tuple<size_t, size_t> maxIndex = { std::get<0>(elements_[0]), std::get<1>(elements_[0]) };

        for (size_t i = 1; i < elements_.size(); ++i) {
            const T value = std::get<2>(elements_[i]);
            const size_t r = std::get<0>(elements_[i]);
            const size_t c = std::get<1>(elements_[i]);

            if (value < minValue) {
                minValue = value;
                minIndex = { r, c };
            }
            if (value > maxValue) {
                maxValue = value;
                maxIndex = { r, c };
            }
        }
        return { minValue, minIndex, maxValue, maxIndex }; 
    }

    size_t rows() const { return rows_; }
    size_t cols() const { return cols_; }

private:
    size_t rows_, cols_;
    std::vector<std::tuple<size_t, size_t, T>> elements_;
};

template <typename T>
SparseMatrix<T> readMatrixFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Could not open file");
    }

    size_t rows, cols;
    file >> rows >> cols;

    SparseMatrix<T> matrix(rows, cols);
    size_t r, c;
    T value;

    while (file >> r >> c >> value) {
        matrix.insert(r, c, value);
    }

    return matrix;
}

template <typename T>
void writeResultToFile(const std::string& filename, T minValue, std::tuple<size_t, size_t> minIndex,
    T maxValue, std::tuple<size_t, size_t> maxIndex) {
    std::ofstream file(filename);
    if (!file) {
        throw std::runtime_error("Could not open file for writing");
    }

    file << "Min Value: " << minValue << " at ("
        << std::get<0>(minIndex) << ", " << std::get<1>(minIndex) << ")\n";
    file << "Max Value: " << maxValue << " at ("
        << std::get<0>(maxIndex) << ", " << std::get<1>(maxIndex) << ")\n";
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <output_file>" << std::endl;
        return 1;
    }

    try {
            SparseMatrix<int> matrix = readMatrixFromFile<int>(argv[1]);
        int minValue; 
        std::tuple<size_t, size_t> minIndex;
        int maxValue; 
        std::tuple<size_t, size_t> maxIndex;

        std::tie(minValue, minIndex, maxValue, maxIndex) = matrix.minMax();

        writeResultToFile(argv[2], minValue, minIndex, maxValue, maxIndex);

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}