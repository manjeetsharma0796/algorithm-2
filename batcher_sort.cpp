#include <iostream>
using namespace std;
void compare_interchange(int &x, int &y) {
    if (x > y) {
        int temp = x;
        x        = y;
        y        = temp;
    }
}
int *merge(int u[], int v[], int m, int n) {
    int *s;
    if (m == 0) {
        s    = new int;
        s[0] = v[0];
    } else if (n == 0) {
        s    = new int;
        s[0] = u[0];
    } else if (m == 1 && n == 1) {
        compare_interchange(u[0], v[0]);
        s    = new int[2];
        s[0] = u[0];
        s[1] = v[0];
    } else {
        int x, y, c;
        if (m % 2 == 1)
            x = (m / 2) + 1;
        else
            x = m / 2;
        if (n % 2 == 1)
            y = (n / 2) + 1;
        else
            y = n / 2;
        int *ou = new int[x];
        int *ov = new int[y];
        for (int i = 0, j = 0; i < m; i += 2, j++)
            ou[j] = u[i];
        for (int i = 0, j = 0; i < n; i += 2, j++)
            ov[j] = v[i];
        int *a  = merge(ou, ov, x, y);
        int *eu = new int[m / 2];
        int *ev = new int[n / 2];
        for (int i = 1, j = 0; i < m; i += 2, j++)
            eu[j] = u[i];
        for (int i = 1, j = 0; i < n; i += 2, j++)
            ev[j] = v[i];
        int *b = merge(eu, ev, m / 2, n / 2);
        if (m % 2 == 0 && n % 2 == 0)
            c = (m / 2) + (n / 2) - 1;
        else
            c = (m / 2) + (n / 2);
        for (int i = 1; i <= c; i++)
            compare_interchange(b[i - 1], a[i]);
        s    = new int[m + n];
        s[0] = a[0];
        int i, j;
        for (i = 1, j = 1; i <= c; i++) {
            s[j++] = b[i - 1];
            s[j++] = a[i];
        }
        if (m % 2 == 0 && n % 2 == 0)
            s[j++] = b[(m / 2) + (n / 2) - 1];
        else if (m % 2 == 1 && n % 2 == 1)
            s[j++] = a[(m / 2) + (n / 2) + 1];
        delete[] ou;
        delete[] ov;
        delete[] eu;
        delete[] ev;
        delete[] a;
        delete[] b;
    }
    return s;
}
int *sort(int arr[], int lo, int no) {
    int *s;
    int m, n;
    if (no > 1) {
        m      = no / 2;
        n      = no - m;
        int *u = new int[m];
        int *v = new int[n];
        u      = sort(arr, lo, m);
        v      = sort(arr, lo + m, n);
        s      = merge(u, v, m, n);
        delete[] u;
        delete[] v;
        return s;
    } else {
        s    = new int;
        s[0] = arr[lo];
        return s;
    }
}
int main() {
    int n;
    cout << "Enter no of elements :" << endl;
    cin >> n;
    int *arr = new int[n];
    cout << "Enter elements :" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int *s = sort(arr, 0, n);
    for (int i = 0; i < n; i++)
        cout << s[i] << " ";
    return 0;
}