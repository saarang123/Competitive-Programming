#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4002;
const int inf = 1e17;
int dp[N][N][2], a[2 * N];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/input.txt", "r", stdin);
        freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/output.txt", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    for(int f = 1; f <= n; f++) cin >> a[f];
    a[n + 1] = a[1];
    int ans = max(0LL, a[1]);
    dp[1][0][0] = 0; dp[1][1][1] = a[1];
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= min(i, k); j++) {
            dp[i][j][0] = dp[i - 1][j][0];
            if(i > 1) dp[i][j][0] = max(dp[i][j][0], a[i] + dp[i - 2][j - 1][0]);
            dp[i][j][1] = dp[i - 1][j][1];
            if(i > 1 && i < n) dp[i][j][1] = max(dp[i][j][1], a[i] + dp[i - 2][j - 1][1]);
            ans = max(ans, dp[i][j][0]);
            ans = max(ans, dp[i][j][1]);
        }
    }
    cout << ans << '\n';
    return 0;
}