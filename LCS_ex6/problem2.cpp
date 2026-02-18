#include <iostream>
#include <string>
using namespace std;

int recursiveLCS(string X, string Y, int m, int n) {

    if (m == 0 || n == 0)
        return 0;

    if (X[m - 1] == Y[n - 1])
        return 1 + recursiveLCS(X, Y, m - 1, n - 1);
    else
        return max(recursiveLCS(X, Y, m - 1, n),
                   recursiveLCS(X, Y, m, n - 1));
}

int main() {
    string X, Y;

    cout << "Enter first sequence: ";
    cin >> X;

    cout << "Enter second sequence: ";
    cin >> Y;

    int m = X.length();
    int n = Y.length();

    int length = recursiveLCS(X, Y, m, n);

    cout << "\nLength of Longest Common Subsequence: " << length << endl;

    return 0;
}
