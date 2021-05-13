#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
using namespace std;
const int mxn = 20;
long long dp[1 << mxn][mxn];
int a[mxn], bin[mxn], ter[mxn];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    	int c = 0;
    	for(int j = 0; j < 31; j++)
    		c += (a[i] >> j & 1);
    	bin[i] = c;
    	int f = 0, x = a[i];
    	while(x) {
    		f += (x % 3 == 1);
    		x /= 3;
    	}
    	ter[i] = f;
    }
    for(int i = 0; i < n; i++)
    	dp[1 << i][i] = 1;
    for(int mask = 1; mask < (1 << n); mask++) {
    	for(int i = 0; i < n; i++) if(!(mask >> i & 1)) {
    		for(int j = 0; j < n; j++) if(mask >> j & 1)
    			if(bin[i] == bin[j] || ter[i] == ter[j])
    				dp[mask ^ (1 << i)][i] += dp[mask][j];
    	}
    }
    long long ans = 0;
    for(int i = 0; i < n; i++)
    	ans += dp[(1 << n) - 1][i];
    cout << ans << '\n';
    return 0;
}