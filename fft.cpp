// FFT
#include <cmath>
#include <complex>
#include <iostream>
using namespace std;
void recursiveFFT(complex<double> S[], int N, complex<double> A[]) {
    if (N == 1) {
        A[0] = S[0];
        return;
    }
    if (N % 2 != 0) {
        cerr << "Input size must be a power of 2" << endl;
        exit(1);
    }
    complex<double> w = exp(-2.0 * complex<double>(0, M_PI) / complex<double>(N));
    complex<double> p = 1.0;
    complex<double> X[N / 2];
    complex<double> Y[N / 2];
    for (int i = 0; i < N / 2; i++) {
        X[i] = S[2 * i];
        Y[i] = S[2 * i + 1];
    }
    complex<double> B[N / 2];
    complex<double> C[N / 2];
    recursiveFFT(X, N / 2, B);
    recursiveFFT(Y, N / 2, C);
    for (int r = 0; r < N / 2; r++) {
        complex<double> term = p * C[r];
        A[r]                 = B[r] + term;
        A[r + N / 2]         = B[r] - term;
        p *= w;
    }
}
int main() {
    int N = 16;
    complex<double> S[N];
    for (int i = 0; i < N; i++) {
        S[i] = i + 1;
    }
    if ((N & (N - 1)) != 0) {
        cout << "Input size is not a power of 2. Please provide input of size 2^k." << endl;
        return 1;
    }
    complex<double> A[N];
    recursiveFFT(S, N, A);
    cout << "FFT result:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "A[" << i << "] = " << A[i].real() << " + " << A[i].imag() << "i" << endl;
    }
    return 0;
}