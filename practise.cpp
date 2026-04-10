#include <bits/stdc++.h>
using namespace std;

int main() {
    string txt,pat;
    cout << "Enter the text"<<endl;
    cin>>txt;
    cout << "Enter the pattern :"<<endl;
    cin>>pat;

    int n = txt.size();
    int m = pat.size();

    int d = 256, q = 101;
    int h = 1, p = 0 , t = 0;

    for(int i=0;i<m-1;i++) {
        h = (h * d) % q;
    }

    for(int i=0;i<m;i++) {
        p = (p*d + pat[i])%q;
        t = (t*d + txt[i])%q;
    }

    for(int i=0;i<=n-m;i++) {
        if(p==t) {
            if(txt.substr(i,m) == pat) {
                cout<<"Pattern found at index "<<i<<endl;
            }
        }
        if(i<n-m) {
            t = (d * (t - txt[i] * h) + txt[i+m]) % q;
            if(t < 0) t += q;
        }
    }
    return 0;
}