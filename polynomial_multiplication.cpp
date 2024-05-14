#include <iostream>
using namespace std;
int multiplyPolynomials(int a[], int b[], int degreeA, int degreeB) {
    int degreeResult = degreeA + degreeB;
    int* result      = new int[degreeResult + 1]();  // Dynamically allocate memory for the resultarray and initialize to 0
    for (int i = 0; i <= degreeA; i++) {
        for (int j = 0; j <= degreeB; j++) {
            result[i + j] += a[i] * b[j];
        }
    }
    // Find the highest degree of the resulting polynomial
    while (degreeResult >= 0 && result[degreeResult] == 0) {
        degreeResult--;
    }
    delete[] result;  // Free dynamically allocated memory
    return degreeResult;
}
void printPolynomial(int coefficients[], int degree) {
    for (int i = degree; i >= 0; i--) {
        if (coefficients[i] != 0) {
            if (i == degree) {
                cout << coefficients[i];
            } else if (coefficients[i] > 0) {
                cout << " + " << coefficients[i];
            } else {
                cout << " - " << -coefficients[i];
            }
            if (i > 1) {
                cout << "x^" << i;
            } else if (i == 1) {
                cout << "x";
            }
        }
    }
    cout << endl;
}
int main() {
    int degreeA, degreeB;
    cout << "Enter the degree of polynomial A: ";
    cin >> degreeA;
    int* a = new int[degreeA + 1];
    cout << "Enter the coefficients of polynomial A (from highest degree to lowest): ";

    for (int i = degreeA; i >= 0; i--) {
        cin >> a[i];
    }

    cout << "Enter the degree of polynomial B: ";
    cin >> degreeB;

    int* b = new int[degreeB + 1];
    cout << "Enter the coefficients of polynomial B (from highest degree to lowest): ";
    for (int i = degreeB; i >= 0; i--) {
        cin >> b[i];
    }

    int resultDegree = multiplyPolynomials(a, b, degreeA, degreeB);
    cout << "Polynomial A: ";
    printPolynomial(a, degreeA);
    cout << "Polynomial B: ";
    printPolynomial(b, degreeB);
    cout << "Degree of the product of Polynomials A and B: " << resultDegree << std::endl;

    delete[] a;  // Free dynamically allocated memory
    delete[] b;  // Free dynamically allocated memory
    return 0;
}