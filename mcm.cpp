#include <iostream>
using namespace std;

int m[100][100], s[100][100];

// Function to print optimal parenthesis
void printOrder(int i, int j) {
    if (i == j) {
        cout << "A" << i;
        return;
    }
    cout << "(";
    printOrder(i, s[i][j]);
    printOrder(s[i][j] + 1, j);
    cout << ")";
}

int main() {
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;

    int p[n + 1];
    cout << "Enter dimensions array (size " << n + 1 << "): ";
    for (int i = 0; i <= n; i++) cin >> p[i];

    // Step 1: Initialize
    for (int i = 1; i <= n; i++)
        m[i][i] = 0;

    // Step 2: Chain length
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = 1e9;

            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "\nMinimum multiplications: " << m[1][n] << endl;

    cout << "Optimal parenthesization: ";
    printOrder(1, n);
    cout << endl;

    return 0;
}