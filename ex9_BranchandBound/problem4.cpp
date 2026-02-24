#include <bits/stdc++.h>
using namespace std;

struct Item {
    int weight;
    int profit;
    double ratio;
};

struct Node {
    int level;
    int weight;
    int profit;
    double bound;
};

// Sort items by profit/weight ratio (descending)
bool cmp(Item a, Item b) {
    return a.ratio > b.ratio;
}

// Bounding function (fractional knapsack bound)
double calculateBound(Node u, int n, int W, vector<Item>& items) {

    if (u.weight >= W)
        return 0;

    double bound = u.profit;
    int totalWeight = u.weight;

    for (int i = u.level + 1; i < n; i++) {
        if (totalWeight + items[i].weight <= W) {
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

// Comparator for priority queue (max heap based on bound)
struct Compare {
    bool operator()(Node const &a, Node const &b) {
        return a.bound < b.bound;
    }
};

int branchAndBound(vector<Item>& items, int W) {

    int n = items.size();
    sort(items.begin(), items.end(), cmp);

    priority_queue<Node, vector<Node>, Compare> pq;

    Node u, v;

    v.level = -1;
    v.weight = 0;
    v.profit = 0;
    v.bound = calculateBound(v, n, W, items);

    pq.push(v);

    int maxProfit = 0;

    while (!pq.empty()) {

        v = pq.top();
        pq.pop();

        if (v.bound <= maxProfit)
            continue;

        u.level = v.level + 1;

        if (u.level >= n)
            continue;

        // Include item
        u.weight = v.weight + items[u.level].weight;
        u.profit = v.profit + items[u.level].profit;

        if (u.weight <= W) {
            maxProfit = max(maxProfit, u.profit);
            u.bound = calculateBound(u, n, W, items);
            if (u.bound > maxProfit)
                pq.push(u);
        }

        // Exclude item
        u.weight = v.weight;
        u.profit = v.profit;
        u.bound = calculateBound(u, n, W, items);

        if (u.bound > maxProfit)
            pq.push(u);
    }

    return maxProfit;
}

int main() {

    int W, n;

    cout << "Enter capacity: ";
    cin >> W;

    cout << "Enter number of initial items: ";
    cin >> n;

    vector<Item> items(n);

    cout << "Enter weight and profit for initial items:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].profit;
        items[i].ratio =
            (double)items[i].profit / items[i].weight;
    }

    int initialProfit = branchAndBound(items, W);
    cout << "Initial Maximum Profit = " << initialProfit << endl;

    // New item insertion
    Item newItem;
    cout << "Enter new item (weight profit): ";
    cin >> newItem.weight >> newItem.profit;
    newItem.ratio =
        (double)newItem.profit / newItem.weight;

    items.push_back(newItem);

    int updatedProfit = branchAndBound(items, W);
    cout << "Updated Maximum Profit = " << updatedProfit << endl;

    return 0;
}