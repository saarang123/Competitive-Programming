#include <bits/stdc++.h>
using namespace std;

const int N = 102;
const int inf = 1000 * 1000 * 1000;
const int bias = N * N * 10;
int dp[N][2 * bias];
int a[N], b[N];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i], b[i] *= m;
    for(int i = 0; i < n; i++) for(int j = 0; j < 2 * bias; j++) dp[i][j] = -inf;
    dp[0][bias] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2 * bias; j++) {
            dp[i + 1][j - a[i] + b[i]] = max(dp[i + 1][j - a[i] + b[i]], dp[i][j] + a[i]);
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        }
    }
    cout << (dp[n][bias] <= 0 ? -1 : dp[n][bias]) << '\n';
    return 0;
}
