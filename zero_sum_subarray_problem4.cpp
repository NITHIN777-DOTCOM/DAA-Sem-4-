#include <iostream>
#include <vector>
#include <unordered_map>
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

    unordered_map<long long, int> prefixIndex;
    long long prefixSum = 0;

    prefixIndex[0] = -1;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if (prefixIndex.find(prefixSum) != prefixIndex.end()) {
            int start = prefixIndex[prefixSum] + 1;
            int end = i;
            cout << "Start Index = " << start << endl;
            cout << "End Index   = " << end << endl;
            return 0;
        }

        prefixIndex[prefixSum] = i;
    }

    cout << "Start Index = -1" << endl;
    cout << "End Index   = -1" << endl;

    return 0;
}
