#include <bits/stdc++.h>
using namespace std;

// brute force min cut
int bruteMinCut(vector<vector<int>>& w, int n) {
    int minCut = INT_MAX;

    // all subsets except empty and full
    for (int mask = 1; mask < (1 << n) - 1; mask++) {
        int cut = 0;

        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if ((mask & (1 << u)) && !(mask & (1 << v))) {
                    cut += w[u][v];
                }
            }
        }

        minCut = min(minCut, cut);
    }

    return minCut;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> w(n, vector<int>(n));

    // input adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }

    cout << "Min Cut = " << bruteMinCut(w, n) << endl;

    return 0;
}