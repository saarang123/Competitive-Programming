#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 502, C = 1002;
const int inf = 1e12;
int p[N], d[N], r[N];
vector<vector<int>> dp(N, vector<int>(C, inf));
int n, m, c;
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    cin >> n >> m >> c;
    for(int i = 1; i <= n; i++) cin >> p[i] >> d[i] >> r[i];
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j >= 1; j--) {
            for(int k = 0; k <= c; k++) {
                dp[j][k] = min(dp[j][k], dp[j - 1][k] + p[i]);
                if(k - r[i] >= 0)
                    dp[j][k] = min(dp[j][k], dp[j - 1][k - r[i]] + d[i]);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= n; i++) for(int j = 0; j <= c; j++)
        if(dp[i][j] <= m)
            ans = max(ans, i);
    cout << ans << '\n';
    return 0;
}
