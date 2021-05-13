#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[1003];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n, m, t;
    cin >> n >> m >> t;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int c; cin >> c;
            int cost = 2 * (i + j);
            for(int w = t - cost; w >= 0; w--)
                ans = max(ans, dp[w + cost] = max(dp[w + cost], dp[w] + c));
        }
    }
    cout << ans << '\n';
    return 0;
}
