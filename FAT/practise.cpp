#include <bits/stdc++.h>
using namespace std;


int main() {
    string text, pattern;
    cin >> text >> pattern;

    int n = text.size(),m = pattern.size();

    int d = 256,q=101,h=1,p=0,t=0;

    for(int i=0;i<m-1;i++) h = (h*d) % q;

    for(int i=0;i<m;i++) {
        p = (p*d +pattern[i]) % q;
        t = (t*d + text[i]) % q;
    }

    for(int i=0;i<=n-m;i++) {
        if(p==t) {
            if(text.substr(i,m)==pattern) {
                cout << "patter found at" << i <<endl;
            }
        }
        if(i<n-m) {
            t =(d*(t -text[i] *h) + text[i+m]) %q;
            if(t<0) t+=q;
        }
    }
    
}