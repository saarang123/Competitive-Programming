#include <bits/stdc++.h>
using namespace std;
#define int long long

int f(int x, int y) {
    if(y < 0) return ((x * (x + 1)) / 2) + abs(y);
    return ((x * (x + 1)) / 2) - ((y * (y + 1)) / 2);
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int mn = 1, mx = m;
    while(mn < mx) {
        int mid = (mn + mx + 1) >> 1;
        int left = k - 1, right = n - k;
        int sum = mid + f(mid - 1, mid - 1 - left) * (left > 0) + f(mid - 1, mid - 1 - right);
        //cout << mn << ' ' << mid << ' ' << mx << ' ' << sum << '\n';
        if(sum <= m)
            mn = mid;
        else
            mx = mid - 1;
    }
    cout << mn << '\n';
    return 0;
}
