#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 16;
int dp[1 << N];
int a[N][N];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> a[i][j];
    for(int mask = 0; mask < (1 << n); mask++) {
        for(int i = 0; i < n; i++)
            for(int j = i; j < n; j++)
                if((mask >> i & 1) && (mask >> j & 1))
                    dp[mask] += a[i][j];
        for(int smask = mask; smask; smask = (smask - 1) & mask)
            dp[mask] = max(dp[mask], dp[smask] + dp[mask ^ smask]);
    }
    cout << dp[(1 << n) - 1] << '\n';
    return 0;
}
