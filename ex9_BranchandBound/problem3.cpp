#include <bits/stdc++.h>
using namespace std;

struct Item {
    string name;
    int weight;
    int profit;
    double ratio;
};

struct Node {
    int level;
    int weight;
    int profit;
    vector<bool> selected;
    double bound;
};

bool cmp(Item a, Item b) {
    return a.ratio > b.ratio;
}

// Bounding Function
double calculateBound(Node u, int n, int W, vector<Item>& items,
                      int bonus_i, int bonus_j, int bonus_val) {

    if (u.weight > W)
        return 0;

    double bound = u.profit;
    int totalWeight = u.weight;

    // Fractional knapsack style bound
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

    // Optimistically assume bonus can still happen
    if (!u.selected[bonus_i] || !u.selected[bonus_j])
        bound += bonus_val;

    return bound;
}

int main() {

    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter capacity: ";
    cin >> W;

    vector<Item> items(n);

    cout << "Enter item name, weight, profit:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].name >> items[i].weight >> items[i].profit;
        items[i].ratio =
            (double)items[i].profit / items[i].weight;
    }

    // Bonus input
    string b1, b2;
    int bonus_val;
    cout << "\nEnter bonus pair (item1 item2 bonus_value): ";
    cin >> b1 >> b2 >> bonus_val;

    // Penalty input
    string p1, p2;
    int penalty_val;
    cout << "\nEnter penalty pair (item1 item2 penalty_value): ";
    cin >> p1 >> p2 >> penalty_val;

    // Find indices
    int bonus_i=-1, bonus_j=-1, penalty_i=-1, penalty_j=-1;

    for(int i=0;i<n;i++){
        if(items[i].name==b1) bonus_i=i;
        if(items[i].name==b2) bonus_j=i;
        if(items[i].name==p1) penalty_i=i;
        if(items[i].name==p2) penalty_j=i;
    }

    sort(items.begin(), items.end(), cmp);

    queue<Node> Q;
    Node u, v;

    v.level = -1;
    v.weight = 0;
    v.profit = 0;
    v.selected = vector<bool>(n,false);
    v.bound = calculateBound(v,n,W,items,bonus_i,bonus_j,bonus_val);

    Q.push(v);
    int maxProfit = 0;

    while(!Q.empty()) {

        v = Q.front();
        Q.pop();

        if(v.bound <= maxProfit)
            continue;

        u.level = v.level + 1;
        if(u.level >= n)
            continue;

        // Include item
        u.selected = v.selected;
        u.selected[u.level] = true;

        u.weight = v.weight + items[u.level].weight;
        u.profit = v.profit + items[u.level].profit;

        // Apply bonus
        if(u.selected[bonus_i] && u.selected[bonus_j])
            u.profit += bonus_val;

        // Apply penalty
        if(u.selected[penalty_i] && u.selected[penalty_j])
            u.profit -= penalty_val;

        if(u.weight <= W) {
            maxProfit = max(maxProfit, u.profit);
            u.bound = calculateBound(u,n,W,items,
                                     bonus_i,bonus_j,bonus_val);

            if(u.bound > maxProfit)
                Q.push(u);
        }

        // Exclude item
        u.selected = v.selected;
        u.weight = v.weight;
        u.profit = v.profit;

        u.bound = calculateBound(u,n,W,items,
                                 bonus_i,bonus_j,bonus_val);

        if(u.bound > maxProfit)
            Q.push(u);
    }

    cout << "Maximum Profit = " << maxProfit << endl;

    return 0;
}