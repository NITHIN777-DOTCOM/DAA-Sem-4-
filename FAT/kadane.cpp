#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[1000000];
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int maxSum = a[0], currSum = a[0];
    int start = 0, end = 0, tempStart = 0;

    for(int i = 1; i < n; i++) {
        if(currSum + a[i] < a[i]) {
            currSum = a[i];
            tempStart = i;
        } else {
            currSum += a[i];
        }

        if(currSum > maxSum) {
            maxSum = currSum;
            start = tempStart;
            end = i;
        }
    }

    cout << "Start: " << start << endl;
    cout << "End: " << end << endl;
    cout << "Sum: " << maxSum << endl;

    return 0;
}