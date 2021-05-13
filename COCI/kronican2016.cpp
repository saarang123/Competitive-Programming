#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
using namespace std;
const int mxn = 21;
int dp[1 << mxn], a[mxn][mxn];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    	for(int j = 0; j < n; j++)
    		cin >> a[i][j];
    for(int mask = 0; mask < (1 << n); mask++) {
    	if(__builtin_popcount(mask) <= k) {
    		dp[mask] = 0;
    		continue;
    	}
    	dp[mask] = 1e9;
    	for(int i = 0; i < n; i++) if(mask >> i & 1)
    		for(int j = 0; j < n; j++) if(mask >> j & 1) if(i != j)
    			dp[mask] = min(dp[mask], dp[mask ^ (1 << i)] + a[i][j]);
    }
    cout << dp[(1 << n) - 1] << '\n';
    return 0;
}