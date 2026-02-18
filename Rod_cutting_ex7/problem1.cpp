#include <bits/stdc++.h>
#include <ctime>
#include <climits>

using namespace std;

int Cut_rod(int P[], int n, int B[], int S[]) {

    B[0] = 0;

    for(int i = 1; i <= n; i++) {
        int q = INT_MIN;

        for(int k = 1; k <= i; k++) {
            if(q < P[k] + B[i-k]) {
                q = P[k] + B[i-k];
                S[i] = k;
            }
        }

        B[i] = q;
    }

    return B[n];
}

void PRINT_CUT_ROD_SOLUTION(int S[], int n) {

    cout << "Optimal cutting lengths: ";

    while(n > 0) {
        cout << S[n] << " ";
        n = n - S[n];
    }

    cout << endl;
}

int main() {

    int n;

    cout << "Enter the length of the rod: ";
    cin >> n;

    int P[n+1];

    cout << "Enter the prices of rods from length 1 to " << n << ":" << endl;

    P[0] = 0; 

    for(int i = 1; i <= n; i++) {
        cin >> P[i];
    }

    int B[n+1];
    int S[n+1];

    clock_t tStart = clock();

    int maxRevenue = Cut_rod(P, n, B, S);

    cout << "Maximum revenue that can be generated from the rod is: "
         << maxRevenue << endl;

    PRINT_CUT_ROD_SOLUTION(S, n);

    double time1 = (double)(clock() - tStart) / CLOCKS_PER_SEC;

    cout << "Time taken is " << time1 << " seconds" << endl;

    return 0;
}
