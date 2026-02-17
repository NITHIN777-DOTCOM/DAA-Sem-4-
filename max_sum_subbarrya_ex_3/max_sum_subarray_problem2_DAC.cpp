#include <iostream>
#include <vector>
#include <climits>
#include <ctime>
using namespace std;

struct Subarray {
    int left;
    int right;
    long long sum;
};

Subarray maxCrossingSubarray(const vector<int>& arr, int low, int mid, int high) {
    long long leftSum = LLONG_MIN;
    long long sum = 0;
    int maxLeft = mid;

    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > leftSum) {
            leftSum = sum;
            maxLeft = i;
        }
    }

    long long rightSum = LLONG_MIN;
    sum = 0;
    int maxRight = mid + 1;

    for (int j = mid + 1; j <= high; j++) {
        sum += arr[j];
        if (sum > rightSum) {
            rightSum = sum;
            maxRight = j;
        }
    }

    return {maxLeft, maxRight, leftSum + rightSum};
}

Subarray maxSubarray(const vector<int>& arr, int low, int high) {
    if (low == high) {
        return {low, high, arr[low]};
    }

    int mid = (low + high) / 2;

    Subarray left = maxSubarray(arr, low, mid);
    Subarray right = maxSubarray(arr, mid + 1, high);
    Subarray cross = maxCrossingSubarray(arr, low, mid, high);

    if (left.sum >= right.sum && left.sum >= cross.sum)
        return left;
    else if (right.sum >= left.sum && right.sum >= cross.sum)
        return right;
    else
        return cross;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    clock_t start = clock();

    Subarray result = maxSubarray(arr, 0, n - 1);

    clock_t end = clock();

    double execTime = double(end - start) / CLOCKS_PER_SEC;

    cout << "\n--- Result ---\n";
    cout << "Start Index = " << result.left << endl;
    cout << "End Index   = " << result.right << endl;
    cout << "Maximum Sum = " << result.sum << endl;

    cout << "Execution Time = " << execTime << " seconds\n";
    cout << "Time Complexity = O(n log n)\n";

    return 0;
}
