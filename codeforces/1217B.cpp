#include <bits/stdc++.h>
#define int long long

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int t; std::cin >> t;
    while(t--) {
        int n, x, mx = 0;
        std::cin >> n >> x;
        std::vector<std::array<int, 3>> a(n);
        for(int i = 0; i < n; i++) {
            std::cin >> a[i][1] >> a[i][2];
            mx = std::max(mx, a[i][1]);
            a[i][0] = a[i][1] - a[i][2];
        }
        std::sort(a.begin(), a.end());
        std::reverse(a.begin(), a.end());
        if(mx >= x) {
            std::cout << 1 << '\n';
            continue;
        }
        if(a[0][0] <= 0) {
            std::cout << -1 << '\n';
            continue;
        }
        int ans = (x - mx) / a[0][0] + ((x - mx) % a[0][0] > 0) + 1;
        std::cout << ans << '\n';
    }
    return 0;
}
