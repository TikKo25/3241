#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// ������� ���������� �������
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    int swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;

        cout << "������ " << i + 1 << ": ";
        printArray(arr);

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }

        if (minIdx != i) {
            swap(arr[i], arr[minIdx]);
            swaps++;
        }
    }

    cout << "������ " << n << ": ";
    printArray(arr);

    cout << "Swaps: " << swaps << endl;
}

int main() {
    vector<int> arr = { 4, 6, 9, 2, 3, 7, 0, 5, 8, 1 };

    cout << "�������� ������: ";
    printArray(arr);

    selectionSort(arr);

    cout << "��������������� ������: ";
    printArray(arr);

    return 0;
}