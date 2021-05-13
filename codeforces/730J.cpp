#include <bits/stdc++.h>
using namespace std;

const int N = 102;
int dp[N][N * N], a[N], b[N];
int need, n;
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], need += a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    for(int j = 1; j <= n; j++) {
        for(int i = n; i > 0; i--) {
            for(int k = b[j]; k < N * N; k++)
                if(dp[i - 1][k - b[j]] != -1)
                    dp[i][k] = max(dp[i][k], dp[i - 1][k - b[j]] + a[j]);
        }
    }
    int ans = -1;
    for(int i = 1; i <= n; i++) {
        for(int j = need; j < N * N; j++)
            ans = max(ans, dp[i][j]);
        if(ans != -1)
            return cout << i << ' ' << need - ans << '\n', 0;
    }
    return 0;
}
