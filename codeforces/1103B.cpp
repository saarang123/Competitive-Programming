#include <bits/stdc++.h>
using namespace std;

void solve() {
    auto query = [&] (int x, int y) {
        cout << "? " << x << ' ' << y << endl;
        char c; cin >> c;
        if(c == 'e')
            exit(0);
        return c == 'y';
    };
    int p = 1;
    while(query(p, 2 * p))
        p *= 2;
    int mn = p, mx = 2 * p;
    while(mn < mx) {
        int mid = (mn + mx) >> 1;
        if(query(p - 1, mid))
            mn = mid + 1;
        else
            mx = mid;
    }
    cout << "! " << mn << endl;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    string s;
    while(true) {
        cin >> s;
        if(s[0] != 's')
            exit(0);
        solve();
    }
    return 0;
}