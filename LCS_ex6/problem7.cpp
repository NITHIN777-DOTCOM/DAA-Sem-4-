#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string X, Y;

    cout << "Enter first sequence: ";
    cin >> X;

    cout << "Enter second sequence: ";
    cin >> Y;

    // Reverse both sequences
    reverse(X.begin(), X.end());
    reverse(Y.begin(), Y.end());

    int m = X.length();
    int n = Y.length();

    vector<vector<int>> C(m + 1, vector<int>(n + 1, 0));

    // LCS DP
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1])
                C[i][j] = C[i - 1][j - 1] + 1;
            else
                C[i][j] = max(C[i - 1][j], C[i][j - 1]);
        }
    }

    cout << "\nLength of Maximum Common Alternative Sequence: "
         << C[m][n] << endl;

    return 0;
}
