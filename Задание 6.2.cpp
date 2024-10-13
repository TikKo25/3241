#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX_SIZE = 100; 

int main() {
    double numbers[MAX_SIZE];
    int numCount = 0;
    double num;

    cout << "Enter numbers (enter 0 to stop): " << endl;

    while (true) {
        cin >> num;
        if (num == 0 || numCount == MAX_SIZE) break;
        numbers[numCount++] = num;
    }

    cout << "n: " << numCount << endl;

    sort(numbers, numbers + numCount);
    cout << " : ";
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