#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e15;
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    vector<array<int, 3>> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2], a[i][2] = min(a[i][2], k);
    sort(a.begin() + 1, a.end());
    int y = 0;
    for(int i = 1; i <= n; i++) y = max(y, a[i][2]);
    if(y >= k) return cout << (int) 1e9 << '\n', 0;
    auto fix = [&] (int mid) {
        vector<int> dp(n + 1);
        dp[n] = a[n][2];
        for(int i = n - 1; i; i--) {
            dp[i] = a[i][2];
            array<int, 3> test = {a[i][1] + mid, 0, 0};
            auto id = lower_bound(a.begin() + i, a.end(), test);
            if(id == a.end()) { dp[i] = max(dp[i], dp[i + 1]); continue; }
            int index = id - a.begin();
            dp[i] += dp[index];
            dp[i] = max(dp[i], dp[i + 1]);
        }
        return (dp[1] >= k);
    };
    int mn = 0, mx = 1e9;
    while(mn < mx) {
        int mid = (mn + mx + 1) >> 1;
        bool ok = fix(mid);
        if(ok) mn = mid;
        else mx = mid - 1;
    }
    if(fix(mn)) cout << mn << '\n';
    else cout << -1 << '\n';
    return 0;
}