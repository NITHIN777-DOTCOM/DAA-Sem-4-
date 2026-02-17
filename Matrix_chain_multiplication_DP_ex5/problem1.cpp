#include <iostream>
using namespace std;

#define MAX 100

long long dp[MAX][MAX];

long long countParenthesizations(int n) {

    for (int i = 1; i <= n; i++) {
        dp[i][i] = 1;
    }

    for (int l = 2; l <= n; l++) {

        for (int i = 1; i <= n - l + 1; i++) {

            int j = i + l - 1;
            dp[i][j] = 0;

            for (int k = i; k <= j - 1; k++) {

                dp[i][j] += dp[i][k] * dp[k + 1][j];
            }
        }
    }

    return dp[1][n];
}

int main() {

    int n;

    cout << "Enter number of matrices: ";
    cin >> n;

    cout << "Number of ways to parenthesize: "
         << countParenthesizations(n) << endl;

    return 0;
}
