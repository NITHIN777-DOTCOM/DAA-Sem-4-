#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements in the array : \n";
    cin >> n;

    cout << "Enter the elements of the array : \n";
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long maxSum = LLONG_MIN;
    long long currSum = 0;

    for (int i = 0; i < n; i++) {
        currSum += arr[i];
        if (currSum > maxSum)
            maxSum = currSum;
        if (currSum < 0)
            currSum = 0;
    }

    long long sum = 0;
    int start = 0;
    int bestStart = 0, bestEnd = 0;
    int bestLength = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == maxSum) {
            int len = i - start + 1;
            if (len > bestLength) {
                bestLength = len;
                bestStart = start;
                bestEnd = i;
            }
        }

        if (sum < 0) {
            sum = 0;
            start = i + 1;
        }
    }

    cout << "Start Index = " << bestStart << endl;
    cout << "End Index   = " << bestEnd << endl;
    cout << "Maximum Sum = " << maxSum << endl;

    return 0;
}
