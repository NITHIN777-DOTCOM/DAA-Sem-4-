#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Item {
    int w, v;
    float r;
};

struct Node {
    int level, profit, weight;
    float bound;
};

// sort by value/weight
bool cmp(Item a, Item b) {
    return a.r > b.r;
}

// calculate bound
float bound(Node u, int n, int W, Item a[]) {
    if(u.weight >= W) return 0;

    float profit = u.profit;
    int j = u.level + 1;
    int totW = u.weight;

    while(j < n && totW + a[j].w <= W) {
        totW += a[j].w;
        profit += a[j].v;
        j++;
    }

    if(j < n)
        profit += (W - totW) * a[j].r;

    return profit;
}

int knapsack(int W, Item a[], int n) {
    sort(a, a+n, cmp);

    queue<Node> q;
    Node u, v;

    v = {-1, 0, 0, 0};
    v.bound = bound(v, n, W, a);
    q.push(v);

    int maxProfit = 0;

    while(!q.empty()) {
        v = q.front(); q.pop();

        if(v.level == n-1) continue;

        u.level = v.level + 1;

        // include
        u.weight = v.weight + a[u.level].w;
        u.profit = v.profit + a[u.level].v;

        if(u.weight <= W && u.profit > maxProfit)
            maxProfit = u.profit;

        u.bound = bound(u, n, W, a);
        if(u.bound > maxProfit)
            q.push(u);

        // exclude
        u.weight = v.weight;
        u.profit = v.profit;
        u.bound = bound(u, n, W, a);

        if(u.bound > maxProfit)
            q.push(u);
    }

    return maxProfit;
}

int main() {
    int n, W;
    cin >> n >> W;

    Item a[100];

    for(int i = 0; i < n; i++) {
        cin >> a[i].v >> a[i].w;
        a[i].r = (float)a[i].v / a[i].w;
    }

    cout << "Max Profit: " << knapsack(W, a, n);

    return 0;
}