#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
    const int MAX_SIZE = 62;
    double numbers[MAX_SIZE];
    int numCount = 0;

    for (int i = 1; i < argc && numCount < MAX_SIZE; i++) {
        double num = atof(argv[i]);
        if (num == 0) break;
        numbers[numCount++] = num;
    }

    for (int i = argc; cin >> numbers[numCount++];);
    numCount--;

    if (numCount < MAX_SIZE) {
        cout << "Number of entered values: " << numCount << endl;
    }

    sort(numbers, numbers + numCount);
    cout << ": ";
    for (int i = 0; i < numCount; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    double sum = 0;
    for (int i = 0; i < numCount; i++) {
        sum += numbers[i];
    }
    double mean = sum / numCount;
    cout << "Mean: " << mean << endl;

    double median;
    if (numCount % 2 == 0) {
        median = (numbers[numCount / 2 - 1] + numbers[numCount / 2]) / 2;
    }
    else {
        median = numbers[numCount / 2];
    }
    cout << "Median: " << median << endl;

    double variance = 0;
    for (int i = 0; i < numCount; i++) {
        variance += (numbers[i] - mean) * (numbers[i] - mean);
    }
    variance /= numCount;
    double stddev = sqrt(variance);
    cout << "Standard deviation: " << stddev << endl;

    cout << "Minimum: " << numbers[0] << endl;
    cout << "Maximum: " << numbers[numCount - 1] << endl;

    return 0;
}