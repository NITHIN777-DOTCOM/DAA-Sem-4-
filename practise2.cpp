#include <bits/stdc++.h>
using namespace std;

int m[100][100],s[100][100];

void printOrder(int i,int j) {
    if(i==j) {
        cout << "A" << i;
        return;
    }
    cout<<"(";
    printOrder(i,s[i][j]);
    printOrder(s[i][j]+1,j);
    cout<<")";
}

int main() {
    int n;
    cout << "Enter the number of matrices : "<<endl;
    cin >> n;

    int p[n+1];
    cout <<"Enter the dimensions :"<<endl;
    for(int i=0;i<n+1;i++) {
        cin>>p[i];
    }
    for(int i=1;i<=n;i++) {
        m[i][i] = 0;
    }

    for(int l=2;l<=n;l++) {
        for(int i=1;i<=n-l-1;i++) {
            int j = i + l - 1;
            m[i][j] = 1e9;
            for(int k=i;k<j;k++) {
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[j]*p[k];
                if(q<m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }


    cout << "Number of multiplications : "<< m[1,n] <<endl;
    cout << "Optimal order" <<endl;
    printOrder(1,n);
}