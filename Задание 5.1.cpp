#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// ������� ���������� ���������
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        cout << "������ " << i << ": ";
        printArray(arr);

        // ���������� ��������, �������, ��� key, ������
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    cout << "������ " << n << ": ";
    printArray(arr);
}

int main() {
    vector<int> arr = { 4, 1, 9, 0, 3, 2, 7, 8, 5, 6 };

    cout << "�������� ������: ";
    printArray(arr);

    insertionSort(arr);

    cout << "��������������� ������: ";
    printArray(arr);

    return 0;
}