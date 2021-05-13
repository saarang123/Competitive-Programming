#include <bits/stdc++.h>
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    int r, n;
    std::cin >> r >> n;
    std::vector<std::array<int, 3>> a(n + 1);
    a[0][0] = 0, a[0][1] = 1, a[0][2] = 1;
    for(int i = 1; i <= n; i++) std::cin >> a[i][0] >> a[i][1] >> a[i][2];
    std::vector<int> dp(n + 1, - 2 * r);
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i - 1; j >= std::max(0, i - 2 * r); j--) {
            if(abs(a[i][1] - a[j][1]) + abs(a[i][2] - a[j][2]) + a[j][0] <= a[i][0])
                dp[i] = std::max(dp[i], dp[j] + 1);
        }
        for(int j = i - 4 * r; j <= i - 2 * r; j++)
            if(j >= 0) dp[i] = std::max(dp[i], dp[j] + 1);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) ans = std::max(ans, dp[i]);
    std::cout << ans << '\n';
    return 0;
}
