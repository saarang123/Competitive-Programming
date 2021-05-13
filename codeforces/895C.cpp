#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 20;
const int mod = 1e9 + 7;
vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
int cost[75], a[1 << 17], dp[2][1 << N];
int f[72], t[100 * 1000 + 4];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    t[0] = 1;
    for(int i = 1; i < 1e5 + 2; i++) (t[i] = t[i - 1] * 2) %= mod;
    for(int i = 1;  i <= 70; i++) {
        int x = i;
        for(int j = 0; j < 19; j++)
            while(x % primes[j] == 0) {
                cost[i] ^= (1 << j);
                x /= primes[j];
            }
    }
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], f[a[i]]++;
    dp[0][0] = 1;
    for(int i = 1, j = 0; i <= 70; i++, j ^= 1) {
        for(int mask = 0; mask < (1 << 19); mask++) {
            if(f[i]) (dp[i & 1][mask ^ cost[i]] += dp[j][mask] * t[max(0LL, f[i] - 1)]) %= mod;
            (dp[i & 1][mask] += dp[j][mask] * t[max(0LL, f[i] - 1)]) %= mod;
        }
        memset(dp[j], 0, sizeof dp[j]);
    }
    cout << (dp[0][0] - 1 + mod) % mod << '\n';
    return 0;
}
