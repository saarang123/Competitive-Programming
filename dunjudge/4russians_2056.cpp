#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5002;
int s[N], c[N], dp[N][N][2]; //0 not taking current, 1 taking current
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
    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 1; i <= n; i++) cin >> s[i];
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) dp[i][j][1] = -1e16;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= min(i, k); j++) {
            dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][0]);
            dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][1] - c[i] * c[i - 1]); //end previous segment
            dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - 1][0] + s[i] - c[i] * c[i - 1]); //start new segment
            if(j >= 2)
                dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - 1][1] + s[i]); //continue segment
        }
    }
    int ans = 0;
    for(int j = 0; j <= k; j++) {
        ans = max(ans, dp[n][j][0]);
        if(j) ans = max(ans, dp[n][j][1]);
    }
    cout << ans << '\n';
    return 0;
}
