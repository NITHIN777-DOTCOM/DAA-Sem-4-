#include <bits/stdc++.h>
using namespace std;

struct Project {
    int cost;
    int profit;
    int risk;
    double efficiency;
};

struct Node {
    int level;
    int profit;
    int cost;
    int risk;
    double bound;
};

bool cmp(Project a, Project b) {
    return a.efficiency > b.efficiency;
}

double calculateBound(Node u, int n, int B, int R, vector<Project>& proj) {
    if (u.cost >= B || u.risk > R)
        return 0;

    double bound = u.profit;
    int totalCost = u.cost;
    int totalRisk = u.risk;

    for (int i = u.level + 1; i < n; i++) {

        int remainingBudget = B - totalCost;
        int remainingRisk = R - totalRisk;

        if (remainingBudget <= 0 || remainingRisk <= 0)
            break;

        if (proj[i].cost <= remainingBudget &&
            proj[i].risk <= remainingRisk) {

            totalCost += proj[i].cost;
            totalRisk += proj[i].risk;
            bound += proj[i].profit;
        } else {
            double fracCost = (double)remainingBudget / proj[i].cost;
            double fracRisk = (double)remainingRisk / proj[i].risk;
            double fraction = min(fracCost, fracRisk);

            bound += proj[i].profit * fraction;
            break;
        }
    }
    return bound;
}

int branchAndBound(int n, int B, int R, vector<Project>& proj) {

    sort(proj.begin(), proj.end(), cmp);

    queue<Node> Q;
    Node u, v;

    v.level = -1;
    v.profit = 0;
    v.cost = 0;
    v.risk = 0;
    v.bound = calculateBound(v, n, B, R, proj);

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

        // Include project
        u.cost = v.cost + proj[u.level].cost;
        u.risk = v.risk + proj[u.level].risk;
        u.profit = v.profit + proj[u.level].profit;

        if (u.cost <= B && u.risk <= R) {
            maxProfit = max(maxProfit, u.profit);
            u.bound = calculateBound(u, n, B, R, proj);
            if (u.bound > maxProfit)
                Q.push(u);
        }

        // Exclude project
        u.cost = v.cost;
        u.risk = v.risk;
        u.profit = v.profit;
        u.bound = calculateBound(u, n, B, R, proj);

        if (u.bound > maxProfit)
            Q.push(u);
    }

    return maxProfit;
}

int main() {

    int n, B, R;

    cout << "Enter number of projects: ";
    cin >> n;

    cout << "Enter budget: ";
    cin >> B;

    cout << "Enter risk limit: ";
    cin >> R;

    vector<Project> proj(n);

    cout << "Enter cost profit risk for each project:\n";

    for (int i = 0; i < n; i++) {
        cin >> proj[i].cost >> proj[i].profit >> proj[i].risk;
        proj[i].efficiency =
            (double)proj[i].profit / (proj[i].cost + proj[i].risk);
    }

    int result = branchAndBound(n, B, R, proj);

    cout << "Maximum Profit = " << result << endl;

    return 0;
}