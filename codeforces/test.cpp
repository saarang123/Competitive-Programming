#include <bits/stdc++.h>
using namespace std;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<int> a;

int query(int x) {
    if(a[x])
        return a[x];
    cout << "? " << x << endl;
    cin >> a[x];
    return a[x];
}

void kek(int x, int y) {
    cout << "! " << x << ' ' << y << endl;
    exit(0);
}

bool in(array<int, 2> x, array<int, 2> y) {
    for(int rep = 0; rep < 2; rep++) {
        if(x[0] <= y[0] && y[0] <= x[1])
            return true;
        swap(x, y);
    }
    return false;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    cin >> n;
    if(n & 1)
        kek(-1, -1);
    a.resize(2 * n + 2);
    query(1); query(1 + n);
    if(a[1] == a[n + 1])
        kek(1, n + 1);
    int mn = 1, mx = n;
    while(mn < mx) {
        int mid = (mn + mx) >> 1;
        query(mid); query(mid + n);
        if(a[mid] == a[n + mid])
            kek(mid, n + mid);
        array<int, 2> x = {min(a[mn], a[mid]), max(a[mn], a[mid])};
        array<int, 2> y = {min(a[mn + n], a[mid + n]), max(a[mn + n], a[n + mid])};
        if(in(x, y))
            mx = mid;
        else
            mn = mid + 1;
    }
    cout << "! -1 -1" << endl;
    return 0;
}