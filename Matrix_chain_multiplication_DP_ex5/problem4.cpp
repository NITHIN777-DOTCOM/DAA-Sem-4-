#include <iostream>
#include <climits>
using namespace std;

#define MAX 100

int M[MAX][MAX];
int S[MAX][MAX];
int p[MAX];

int n;

int MCM(int i, int j) {

    if (i == j)
        return 0;

    if (M[i][j] != -1)
        return M[i][j];

    int minCost = INT_MAX;

    for (int k = i; k < j; k++) {

        int cost = MCM(i, k)
                 + MCM(k + 1, j)
                 + p[i - 1] * p[k] * p[j];

        if (cost < minCost) {
            minCost = cost;
            S[i][j] = k;
        }
    }

    M[i][j] = minCost;
    return M[i][j];
}

void printTables() {

    cout << "\nCost Table (M):\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j < i)
                cout << "0\t";
            else
                cout << M[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nSplit Table (S):\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j <= i)
                cout << "0\t";
            else
                cout << S[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {

    cout << "Enter number of matrices: ";
    cin >> n;

    cout << "Enter dimension array (size " << n + 1 << "): ";
    for (int i = 0; i <= n; i++)
        cin >> p[i];

    // Initialize M with -1
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            M[i][j] = -1;

    int result = MCM(1, n);

    cout << "\nMinimum number of multiplications: "
         << result << endl;

    printTables();

    return 0;
}
