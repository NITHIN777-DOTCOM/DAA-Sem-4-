#include <iostream>
using namespace std;

int n, target;
int a[100];
int x[100];   // solution array (0 or 1)

// backtracking function
void subset(int k, int sum) {

    // if sum matches target → print solution
    if(sum == target) {
        cout << "Subset: ";
        for(int i = 0; i < k; i++) {
            if(x[i] == 1)
                cout << a[i] << " ";
        }
        cout << endl;
        return;
    }

    // if exceeded → stop
    if(k == n || sum > target)
        return;

    // include element
    x[k] = 1;
    subset(k + 1, sum + a[k]);

    // exclude element
    x[k] = 0;
    subset(k + 1, sum);
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    cin >> target;

    subset(0, 0);

    return 0;
}
