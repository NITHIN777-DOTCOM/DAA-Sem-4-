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

    int maxSum = INT_MIN;
    int startIndex = 0, endIndex = 0;

    clock_t start = clock();

    for (int i = 0; i < n; i++) {
        int currentSum = 0;
        for (int j = i; j < n; j++) {
            currentSum += arr[j];

            if (currentSum > maxSum) {
                maxSum = currentSum;
                startIndex = i;
                endIndex = j;
            }
        }
    }

    clock_t end = clock();

    double execTime = double(end - start) / CLOCKS_PER_SEC;

    cout << "Start Index = " << startIndex << endl;
    cout << "End Index   = " << endIndex << endl;
    cout << "Maximum Sum = " << maxSum << endl;
    cout << "Execution Time = " << execTime << " seconds\n";
    cout << "Time Complexity = O(n^2)\n";

    return 0;
}
