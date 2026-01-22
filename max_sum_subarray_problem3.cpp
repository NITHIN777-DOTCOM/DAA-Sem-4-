#include <iostream>
#include <vector>
#include <climits>
#include <ctime>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    clock_t tStart = clock();

    long long maxSum = LLONG_MIN;
    long long currSum = 0;

    int tempStart = 0;
    int bestStart = 0, bestEnd = 0;

    for (int i = 0; i < n; i++) {
        currSum += arr[i];

        if (currSum > maxSum) {
            maxSum = currSum;
            bestStart = tempStart;
            bestEnd = i;
        }

        if (currSum < 0) {
            currSum = 0;
            tempStart = i + 1;
        }
    }

    clock_t tEnd = clock();

    double execTime = double(tEnd - tStart) / CLOCKS_PER_SEC;

    cout << "Start Index = " << bestStart << endl;
    cout << "End Index   = " << bestEnd << endl;
    cout << "Maximum Sum = " << maxSum << endl;
    cout << "Execution Time = " << execTime << " seconds\n";
    cout << "Time Complexity = O(n)\n";

    return 0;
}
