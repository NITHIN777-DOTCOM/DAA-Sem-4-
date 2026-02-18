#include <bits/stdc++.h>
#include <ctime>
#include <climits>

using namespace std;

int price3, price5;

int MaxRevenue(int n) {

    if(n < 3)
        return -n; 

    int maxVal = INT_MIN;

    if(n >= 3)
        maxVal = max(maxVal, price3 + MaxRevenue(n - 3));

    if(n >= 5)
        maxVal = max(maxVal, price5 + MaxRevenue(n - 5));

    if(maxVal == INT_MIN)
        return -n;  

    return maxVal;
}

int main() {

    int n;

    cout << "Enter rod length (>=8): ";
    cin >> n;

    cout << "Enter price of rod length 3: ";
    cin >> price3;

    cout << "Enter price of rod length 5: ";
    cin >> price5;

    clock_t tStart = clock();

    int result = MaxRevenue(n);

    double time1 = (double)(clock() - tStart) / CLOCKS_PER_SEC;

    cout << "Maximum revenue generated: " << result << endl;
    cout << "Time taken: " << time1 << " seconds" << endl;

    return 0;
}
