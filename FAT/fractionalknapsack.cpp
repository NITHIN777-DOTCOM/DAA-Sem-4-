#include <iostream>
using namespace std;

int main() {
    int n, W;
    cin >> n >> W;

    int value[100], weight[100];
    float ratio[100];

    // input
    for(int i = 0; i < n; i++) {
        cin >> value[i] >> weight[i];
        ratio[i] = (float)value[i] / weight[i];
    }

    // bubble sort (descending ratio)
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(ratio[j] < ratio[j+1]) {
                swap(ratio[j], ratio[j+1]);
                swap(value[j], value[j+1]);
                swap(weight[j], weight[j+1]);
            }
        }
    }

    float totalValue = 0;

    for(int i = 0; i < n; i++) {
        if(W >= weight[i]) {
            totalValue += value[i];
            W -= weight[i];
        } else {
            totalValue += ratio[i] * W;
            break;
        }
    }

    cout << "Maximum Value: " << totalValue;

    return 0;
}