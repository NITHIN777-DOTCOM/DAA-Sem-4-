#include <iostream>
#include <climits>
using namespace std;

#define MAX 100

int M[MAX][MAX];
int S[MAX][MAX];

void printOptimal(int i, int j) {
    if (i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        printOptimal(i, S[i][j]);
        printOptimal(S[i][j] + 1, j);
        cout << ")";
    }
}

void matrixChainOrder(int p[], int n) {

    for (int i = 1; i <= n; i++)
        M[i][i] = 0;

    for (int l = 2; l <= n; l++) {

        for (int i = 1; i <= n - l + 1; i++) {

            int j = i + l - 1;
            M[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {

                int q = M[i][k] +
                        M[k + 1][j] +
                        p[i - 1] * p[k] * p[j];

                if (q < M[i][j]) {
                    M[i][j] = q;
                    S[i][j] = k;
                }
            }
        }
    }

    cout << "Minimum number of multiplications: "
         << M[1][n] << endl;

    cout << "Optimal Parenthesization: ";
    printOptimal(1, n);
    cout << endl;
}

int main() {

    int n;

    cout << "Enter number of matrices: ";
    cin >> n;

    int p[n + 1];

    cout << "Enter dimension array (size " << n + 1 << "): ";
    for (int i = 0; i <= n; i++)
        cin >> p[i];

    matrixChainOrder(p, n);

    return 0;
}
