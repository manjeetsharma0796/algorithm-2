#include <iostream>
#include <string>
using namespace std;
void compute_prefix(string pattern, int lps[], int m) {
    int i = 1, len = 0;
    while (i < m) {
        if (pattern[len] == pattern[i]) {
            lps[i] = len + 1;
            len += 1;
            i += 1;
        } else if (len != 0) {
            len = lps[len - 1];
        } else {
            lps[i] = 0;
            i      = i + 1;
        }
    }
}
bool compute_kmp(string pattern, string text) {
    bool yesOrnot = false;
    int n         = text.length();
    int m         = pattern.length();
    int *lps      = new int[m];
    lps[0]        = 0;
    compute_prefix(pattern, lps, m);
    int i = 0, j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            i += 1;
            j += 1;
        } else if (j != 0)
            j = lps[j - 1];
        else
            i += 1;
        if (j == m) {
            cout << pattern << " ";
            j        = lps[j - 1];
            yesOrnot = true;
        }
    }
    return yesOrnot;
}
int main() {
    string pattern;
    string text;
    cout << "Enter the text:" << endl;
    cin >> text;
    cout << "Enter the pattern:";
    cin >> pattern;
    bool yesOrnot = compute_kmp(pattern, text);
    if (yesOrnot == false)
        cout << "Pattern doesn't match" << endl;
    return 0;
}