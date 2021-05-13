#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int N = 22;
bool g[N][N];
int dp[1 << N]; //dp[mask] = number of ways to pair those girls using first __builtin_popcount(mask) guys
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> g[i][j];
    dp[0] = 1;
    for(int mask = 0; mask < (1 << n); mask++) {
        int cnt = __builtin_popcount(mask);
        for(int i = 0; i < n; i++) {
            if(!(mask >> i & 1) && g[cnt][i])
                (dp[mask | (1 << i)] += dp[mask]) %= mod;
        }
    }
    cout << dp[(1 << n) - 1] << '\n';
    return 0;
}
