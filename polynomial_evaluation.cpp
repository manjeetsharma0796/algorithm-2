#include <iostream>
using namespace std;
int main() {
    int n, x;
    cout << "Value of x: ";
    cin >> x;
    cout << "Highest degree: ";
    cin >> n;
    int a[n + 1];
    cout << "Coefficients of polynomial:" << endl;
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }
    int p = a[n], i = n;
    while (i >= 1) {
        p = p * x + a[i - 1];
        i--;
    }
    cout << "REQUIRED: " << p;
    return 0;
}