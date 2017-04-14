#include <bits/stdc++.h>
#include "AccurateSorting.h"

using namespace std;

bool swap(vector<int> &a, int i) {
    int &x = a[i], &y = a[i+1];
    if (abs(y - x) == 1) {
        int z = x;
        x = y;
        y = z;
        return true;
    }
    return false;
}

bool isSorted(vector<int> a) {
    for (int i = 1; i < a.size(); i++) {
        if (a[i] < a[i-1]) return false;
    }
    return true;
}

bool isSortable(vector<int> a, set<vector<int>> visited = set<vector<int>>()) {
    if (isSorted(a)) return true;

    visited.insert(a);
    set<vector<int>> children = set<vector<int>>();
    for (int i = 0; i < a.size()-1; i++) {
        vector<int> child = a;
        if (swap(child,i)) {
            if (isSorted(child)) return true;
            if (!visited.count(child)) children.insert(child);
        }
    }
    for (vector<int> child : children) {
        if (isSortable(child, visited)) return true;
        visited.insert(child);
    }
    return false;
}

int AccurateSorting::main() {
    int q;
    cin >> q;
    for (int r = 0; r < q; r++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << (isSortable(a) ? "Yes" : "No") << endl;
    }
    return 0;
}
