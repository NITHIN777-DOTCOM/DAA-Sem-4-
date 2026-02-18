#include <iostream>
#include <vector>
using namespace std;

int main() {

    string X, Y;
    int k;

    cout << "Enter first sequence: ";
    cin >> X;

    cout << "Enter second sequence: ";
    cin >> Y;

    cout << "Enter value of k: ";
    cin >> k;

    if (X.length() != Y.length()) {
        cout << "\nSequences must be of equal length.\n";
        return 0;
    }

    int n = X.length();
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        if (X[i - 1] == Y[i - 1])
            dp[i] = dp[i - 1];
        else
            dp[i] = dp[i - 1] + 1;
    }

    cout << "\nNumber of changes required: " << dp[n] << endl;

    if (dp[n] == k)
        cout << "Sequences are " << k << "-similar." << endl;
    else
        cout << "Sequences are NOT " << k << "-similar." << endl;

    return 0;
}
