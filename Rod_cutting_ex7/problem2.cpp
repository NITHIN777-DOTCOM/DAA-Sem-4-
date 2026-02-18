#include <bits/stdc++.h>
#include <ctime>
#include <climits>

using namespace std;

int Rod_Cut(int P[], int n) {

    if(n == 0)
        return 0;

    int q = INT_MIN;

    for(int i = 1; i <= n; i++) {
        q = max(q, P[i] + Rod_Cut(P, n-i));
    }

    return q;
}

int main() {

    int n;

    cout << "Enter the length of the rod: ";
    cin >> n;

    int P[n+1];
    P[0] = 0;

    cout << "Enter the prices of rods from length 1 to " << n << ":" << endl;

    for(int i = 1; i <= n; i++) {
        cin >> P[i];
    }

    clock_t tStart = clock();

    int maxRevenue = Rod_Cut(P, n);

    double time1 = (double)(clock() - tStart) / CLOCKS_PER_SEC;

    cout << "Maximum revenue that can be generated from the rod is: "
         << maxRevenue << endl;

    cout << "Time taken is " << time1 << " seconds" << endl;

    return 0;
}
