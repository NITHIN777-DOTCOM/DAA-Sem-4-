#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> X(n);

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> X[i];

    vector<int> L(n, 1);      // LIS length array
    vector<int> prev(n, -1);  // To reconstruct subsequence

    // DP computation
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (X[j] < X[i] && L[j] + 1 > L[i]) {
                L[i] = L[j] + 1;
                prev[i] = j;
            }
        }
    }

    // Find maximum length
    int maxLength = 0, index = 0;
    for (int i = 0; i < n; i++) {
        if (L[i] > maxLength) {
            maxLength = L[i];
            index = i;
        }
    }

    // Reconstruct LIS
    vector<int> LIS;
    while (index != -1) {
        LIS.push_back(X[index]);
        index = prev[index];
    }

    // Print in correct order
    cout << "\nLength of LIS: " << maxLength << endl;
    cout << "Longest Increasing Subsequence: ";

    for (int i = LIS.size() - 1; i >= 0; i--)
        cout << LIS[i] << " ";

    cout << endl;

    return 0;
}
