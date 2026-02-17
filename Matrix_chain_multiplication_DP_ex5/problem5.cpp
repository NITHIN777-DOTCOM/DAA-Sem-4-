#include <iostream>
#include <climits>
using namespace std;

#define MAX 100

int M[MAX][MAX];
int S[MAX][MAX];
int p[MAX];
int n;

int MAX_MCM(int i, int j) {

    if (i == j)
        return 0;

    if (M[i][j] != -1)
        return M[i][j];

    int maxCost = INT_MIN;

    for (int k = i; k < j; k++) {

        int cost = MAX_MCM(i, k)
                 + MAX_MCM(k + 1, j)
                 + p[i - 1] * p[k] * p[j];

        if (cost > maxCost) {
            maxCost = cost;
            S[i][j] = k;
        }
    }

    M[i][j] = maxCost;
    return M[i][j];
}

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

int main() {

    cout << "Enter number of matrices: ";
    cin >> n;

    cout << "Enter dimension array (size " << n + 1 << "): ";
    for (int i = 0; i <= n; i++)
        cin >> p[i];

    // Initialize table
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            M[i][j] = -1;

    int result = MAX_MCM(1, n);

    cout << "\nMaximum number of multiplications: "
         << result << endl;

    cout << "Parenthesization for Maximum Cost: ";
    printOptimal(1, n);
    cout << endl;

    return 0;
}
