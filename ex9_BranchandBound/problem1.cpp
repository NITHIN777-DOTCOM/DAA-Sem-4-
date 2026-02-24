#include <bits/stdc++.h>
using namespace std;

struct Item {
    int weight;
    int profit;
    int deadline;
    double ratio;
};

struct Node {
    int level;
    int profit;
    int weight;
    int time;
    double bound;
};

bool cmp(Item a, Item b) {
    return a.ratio > b.ratio;
}

double calculateBound(Node u, int n, int W, vector<Item>& items) {
    if (u.weight >= W)
        return 0;

    double bound = u.profit;
    int totalWeight = u.weight;
    int currentTime = u.time;

    for (int i = u.level + 1; i < n; i++) {
        if (currentTime + 1 > items[i].deadline)
            continue;

        if (totalWeight + items[i].weight <= W) {
            currentTime++;
            totalWeight += items[i].weight;
            bound += items[i].profit;
        } else {
            int remain = W - totalWeight;
            bound += items[i].ratio * remain;
            break;
        }
    }
    return bound;
}

int branchAndBound(int n, int W, vector<Item>& items) {
    sort(items.begin(), items.end(), cmp);

    queue<Node> Q;
    Node u, v;

    v.level = -1;
    v.profit = 0;
    v.weight = 0;
    v.time = 0;
    v.bound = calculateBound(v, n, W, items);

    Q.push(v);
    int maxProfit = 0;

    while (!Q.empty()) {
        v = Q.front();
        Q.pop();

        if (v.bound <= maxProfit)
            continue;

        u.level = v.level + 1;
        if (u.level >= n)
            continue;

        // Include item
        u.weight = v.weight + items[u.level].weight;
        u.profit = v.profit + items[u.level].profit;
        u.time = v.time + 1;

        if (u.weight <= W && u.time <= items[u.level].deadline) {
            maxProfit = max(maxProfit, u.profit);
            u.bound = calculateBound(u, n, W, items);
            if (u.bound > maxProfit)
                Q.push(u);
        }

        // Exclude item
        u.weight = v.weight;
        u.profit = v.profit;
        u.time = v.time;
        u.bound = calculateBound(u, n, W, items);

        if (u.bound > maxProfit)
            Q.push(u);
    }

    return maxProfit;
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter capacity: ";
    cin >> W;

    vector<Item> items(n);

    cout << "Enter weight profit deadline for each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].profit >> items[i].deadline;
        items[i].ratio = (double)items[i].profit / items[i].weight;
    }

    int result = branchAndBound(n, W, items);

    cout << "Maximum Profit = " << result << endl;

    return 0;
}