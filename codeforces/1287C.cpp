#include <bits/stdc++.h>
using namespace std;
const int N = 102;
int dp[N][N][N][2];
int a[N];
bool f[N];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    int odd = 0, even = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        f[a[i]] = true;
        if(a[i] == 0) a[i] = -1;
        else a[i] %= 2;
    }
    for(int i = 1; i <= n; i++) {
        if(f[i]) continue;
        even += ((i & 1) == 0);
        odd += (i & 1);
    }
    for(int i = 0; i <= n; i++) 
        for(int j = 0; j <= even; j++)
            for(int k = 0; k <= odd; k++)
                for(int l = 0; l < 2; l++)
                    dp[i][j][k][l] = 105;
    dp[0][0][0][0] = dp[0][0][0][1] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= even; j++) {
            for(int k = 0; k <= odd; k++) {
                if(a[i] == -1) {
                    dp[i][j + 1][k][0] = min(dp[i - 1][j][k][0], 1 + dp[i - 1][j][k][1]);
                    dp[i][j][k + 1][1] = min(dp[i - 1][j][k][1], 1 + dp[i - 1][j][k][0]);
                } else if(a[i] == 0) {
                    dp[i][j][k][0] = min(dp[i - 1][j][k][0], 1 + dp[i - 1][j][k][1]);
                } else {
                    dp[i][j][k][1] = min(dp[i - 1][j][k][1], 1  + dp[i - 1][j][k][0]);
                }
            }
        }
    }
    if(a[n] == -1) cout << min(dp[n][even][odd][0], dp[n][even][odd][1]) << '\n';
    else cout << dp[n][even][odd][a[n]] << '\n';
    return 0;
}