#include <bits/stdc++.h>
using namespace std;

int main() {
    string txt = "ABABDABACDABABCABAB", pat = "ABABC";
    int n = txt.size(), m = pat.size();

    int d = 256, q = 101; // base & prime
    int h = 1, p = 0, t = 0;

    // h = d^(m-1) % q
    for(int i = 0; i < m-1; i++) h = (h * d) % q;

    // initial hash
    for(int i = 0; i < m; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for(int i = 0; i <= n - m; i++) {
        if(p == t) { // possible match
            if(txt.substr(i, m) == pat)
                cout << "Pattern found at index " << i << endl;
        }

        // rolling hash
        if(i < n - m) {
            t = (d * (t - txt[i] * h) + txt[i + m]) % q;
            if(t < 0) t += q; // fix negative
        }
    }

    return 0;
}