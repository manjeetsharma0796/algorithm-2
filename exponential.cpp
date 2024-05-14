// exponential
#include <iostream>
using namespace std;
int main() {
    int x, n;
    cout << "Enter value of base: ";
    cin >> x;
    cout << "Enter exponent: ";
    cin >> n;
    int N = n, y = 1, z = x;
    while (N != 0) {
        if (N % 2 != 0)
            y = z * y;
        N = N / 2;
        if (N != 0)
            z = z * z;
    }
    cout << "The value is " << y;
}