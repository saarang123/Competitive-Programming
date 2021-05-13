#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxn = 2003;
int a[mxn], dp[mxn][mxn];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    memset(dp, 0x7f, sizeof dp);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i][i] = 0;
    }
    sort(a + 1, a + n + 1);
    for(int i = n - 1; i; i--)
        for(int j = i + 1; j <= n; j++)
            dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + a[j] - a[i];
    cout << dp[1][n] << '\n';
    return 0;
}