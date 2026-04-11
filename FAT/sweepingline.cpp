#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

struct Segment {
    Point p, q;
};

int orientation(Point a, Point b, Point c) {
    int val = (b.y - a.y)*(c.x - b.x) - (b.x - a.x)*(c.y - b.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

bool intersect(Segment s1, Segment s2) {
    Point p1 = s1.p, q1 = s1.q, p2 = s2.p, q2 = s2.q;

    int o1 = orientation(p1,q1,p2);
    int o2 = orientation(p1,q1,q2);
    int o3 = orientation(p2,q2,p1);
    int o4 = orientation(p2,q2,q1);

    return (o1 != o2 && o3 != o4);
}

int main() {
    int n;
    cout << "Enter number of segments: ";
    cin >> n;

    vector<Segment> seg(n);

    // Input
    for(int i = 0; i < n; i++) {
        cout << "Enter x1 y1 x2 y2 for segment " << i+1 << ": ";
        cin >> seg[i].p.x >> seg[i].p.y >> seg[i].q.x >> seg[i].q.y;
    }

    // Bubble sort based on left x-coordinate
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            int x1 = min(seg[j].p.x, seg[j].q.x);
            int x2 = min(seg[j+1].p.x, seg[j+1].q.x);

            if(x1 > x2) {
                swap(seg[j], seg[j+1]);
            }
        }
    }

    set<int> active;

    for(int i = 0; i < n; i++){
        for(int j : active){
            if(intersect(seg[i], seg[j])){
                cout << "Intersect\n";
            }
        }
        active.insert(i);
    }

    return 0;
}