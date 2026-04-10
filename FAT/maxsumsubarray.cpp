#include <iostream>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Cross sum (important part)
int maxCrossingSum(int a[], int l, int m, int r) {
    int sum = 0;
    int leftSum = -1000000000;

    for(int i = m; i >= l; i--) {
        sum += a[i];
        if(sum > leftSum)
            leftSum = sum;
    }

    sum = 0;
    int rightSum = -1000000000;

    for(int i = m + 1; i <= r; i++) {
        sum += a[i];
        if(sum > rightSum)
            rightSum = sum;
    }

    return leftSum + rightSum;
}

// Main recursive function
int maxSubarray(int a[], int l, int r) {
    if(l == r)
        return a[l];

    int m = (l + r) / 2;

    int left = maxSubarray(a, l, m);
    int right = maxSubarray(a, m + 1, r);
    int cross = maxCrossingSum(a, l, m, r);

    return max(max(left, right), cross);
}

int main() {
    int n;
    cin >> n;

    int a[100000];
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int result = maxSubarray(a, 0, n - 1);

    cout << "Maximum Sum: " << result;

    return 0;
}