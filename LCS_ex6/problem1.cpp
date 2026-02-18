#include <iostream>
#include <vector>
#include <string>
using namespace std;

string bruteForceLCS(string X, string Y) {
    int m = X.length();
    int n = Y.length();

    vector<string> SX, SY;

    for (int mask = 0; mask < (1 << m); mask++) {
        string subseq = "";
        for (int i = 0; i < m; i++) {
            if (mask & (1 << i)) {
                subseq += X[i];
            }
        }
        SX.push_back(subseq);
    }

    for (int mask = 0; mask < (1 << n); mask++) {
        string subseq = "";
        for (int j = 0; j < n; j++) {
            if (mask & (1 << j)) {
                subseq += Y[j];
            }
        }
        SY.push_back(subseq);
    }

    int maxLength = 0;
    string LCS = "";

    for (string s1 : SX) {
        for (string s2 : SY) {
            if (s1 == s2 && s1.length() > maxLength) {
                maxLength = s1.length();
                LCS = s1;
            }
        }
    }

    return LCS;
}

int main() {
    string X, Y;

    cout << "Enter first sequence: ";
    cin >> X;

    cout << "Enter second sequence: ";
    cin >> Y;

    string result = bruteForceLCS(X, Y);

    cout << "\nLongest Common Subsequence: " << result << endl;
    cout << "Length: " << result.length() << endl;

    return 0;
}
