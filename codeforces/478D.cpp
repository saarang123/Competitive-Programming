#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 3;
int dp[2][N];
int r, g;
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> r >> g;
    int sum = r + g, x = 0, m = 0, to_add = 1;
    while(x <= sum) {
    	x += to_add++;
    	m++;
    }
    m--;
    auto f = [&] (int c) { return c * (c + 1) / 2; };
    dp[0][0] = 1;
    for(int i = 1; i <= m; i++) {
    	memset(dp[i & 1], 0, sizeof dp[i & 1]);
    	for(int j = 0; j <= r; j++) {
    		int red = r - j, green = g - (f(i - 1) - j);
    		if(red >= i)
    			(dp[i & 1][j + i] += dp[(i & 1) ^ 1][j]) %= mod;
    		if(green >= i)
    			(dp[i & 1][j] += dp[(i & 1) ^ 1][j]) %= mod;
    	}
    }
    int ans = 0;
    for(int i = 0; i <= r; i++)
    	(ans += dp[m & 1][i]) %= mod;
    cout << ans << '\n';
    return 0;
}