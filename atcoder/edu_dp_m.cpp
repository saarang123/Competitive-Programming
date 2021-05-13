#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 100000 + 3;
const int mod = 1e9 + 7;
int dp[103][N];
int a[103];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 0; i <= a[1]; i++) dp[1][i]++;
    for(int i = 1; i <= k; i++) dp[1][i] += dp[1][i - 1];
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
             dp[i][j] = dp[i - 1][j];
             if(j - a[i] - 1 >= 0) dp[i][j] -= dp[i - 1][j - a[i] - 1];
             //cout << "dp " << i << " " << j << ": " << dp[i][j] << endl;
             dp[i][j] += dp[i][j - 1];
             dp[i][j] %= mod;
             if(dp[i][j] < 0) dp[i][j] += mod;
        }
    }
    //for(int i = 1; i <= n; i++) { for(int j = 0; j <= k; j++) cout << dp[i][j] << " "; cout << endl; }
    int ans = dp[n][k];
    if(k) ans -= dp[n][k - 1];
    ans = (ans + mod) % mod;
    cout << ans << endl;
    return 0;
}
