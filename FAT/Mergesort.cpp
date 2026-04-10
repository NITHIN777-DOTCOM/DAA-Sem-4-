#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &a, int l, int m, int r) {
    vector<int> temp;
    int i = l, j = m + 1;

    while(i <= m && j <= r) {
        if(a[i] <= a[j])
            temp.push_back(a[i++]);
        else
            temp.push_back(a[j++]);
    }

    while(i <= m) temp.push_back(a[i++]);
    while(j <= r) temp.push_back(a[j++]);

    for(int k = l; k <= r; k++)
        a[k] = temp[k - l];
}

void mergeSort(vector<int> &a, int l, int r) {
    if(l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    mergeSort(a, 0, n - 1);

    for(int x : a)
        cout << x << " ";

    return 0;
}