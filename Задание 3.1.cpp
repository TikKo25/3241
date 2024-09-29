#include <iostream>
using namespace std;

int main() {
    int arr[] = { 8, 9, 5, 4, 3, 7, 6, 1, 2, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        cout << "Step " << i + 1 << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
    cout << "Massive: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

