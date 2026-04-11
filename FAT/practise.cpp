#include <bits/stdc++.h>
using namespace std;

int n,target;
int a[100];
int x[100];

void subset(int k,int sum) {
    if(sum==target) {
        cout<<"Subset";
        for(int i=0;i<k;i++) {
            if(x[i] == 1) {
                cout<<a[i];
            }
        }
        return;
    }

    if(k==n || sum > target) {
        return;
    }

    x[k] = 1;
    subset(k+1,sum+a[k]);

    x[k] = 0;
    subset(k+1,sum);
}

int main() {
    cin>>n;

    for(int i=0;i<n;i++) cin>>a[i];

    cin>>target;

    subset(0,0);
    return 0;
}