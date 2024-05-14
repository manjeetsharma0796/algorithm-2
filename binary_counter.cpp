#include <iostream>
using namespace std;
int main() {
    int size;
    cout << "Enter bitsize of array: ";
    cin >> size;
    int *arr = new int(size);
    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }
    int i = 0;
    while (i < size) {
        while (i < size && arr[i] == 1) {
            arr[i] = 0;
            i      = i + 1;
        }
        if (i < size) {
            arr[i] = 1;
            i      = 0;
            for (int z = size - 1; z >= 0; z--) {
                cout << arr[z] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}