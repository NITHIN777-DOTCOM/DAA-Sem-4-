#include <bits/stdc++.h>
using namespace std;

void printCuts(vector<int>& s, int n) {
    cout << "Optimal cuts: ";
    while(n > 0) {
        cout << s[n] << " ";
        n -= s[n];
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    vector<int> price(n+1);
    for(int i = 1; i <= n; i++) cin >> price[i];

    vector<int> dp(n+1, 0), s(n+1, 0);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            if(dp[i] < price[j] + dp[i-j]) {
                dp[i] = price[j] + dp[i-j];
                s[i] = j;   // store cut
            }
        }
    }

    cout << "Maximum Revenue: " << dp[n] << endl;
    printCuts(s, n);
}